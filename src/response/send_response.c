/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** send_response
*/

#include <response.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *get_status_message(status_code_t status_code) {
    for (const status_code_info_t *info = status_codes; info->message != NULL; info++)
        if (info->code == status_code)
            return info->message;
    return "Unknown";
}

size_t get_response_length(const response_t *response)
{
    size_t length = 0;

    length += snprintf(NULL, 0, "HTTP/1.1 %d %s\r\n",
                       response->status_code,
                       get_status_message(response->status_code));
    for (size_t i = 0; i < response->header_count; i++)
        length += strlen(response->headers[i]) + 2;
    length += 2;
    if (response->body && response->body_length > 0)
        length += response->body_length;
    return length;
}

char *format_http_response(const response_t *response) {
    size_t estimated_length = get_response_length(response);
    char *http_response = malloc(estimated_length);

    if (!http_response) {
        fprintf(stderr, "Failed to allocate memory for HTTP response\n");
        return NULL;
    }
    int offset = snprintf(http_response, estimated_length, "HTTP/1.1 %d %s\r\n",
        response->status_code, get_status_message(response->status_code));
    for (size_t i = 0; i < response->header_count; i++)
        offset += snprintf(http_response + offset, estimated_length - offset,
            "%s\r\n", response->headers[i]);
    snprintf(http_response + offset, estimated_length - offset, "\r\n");
    if (response->body && response->body_length > 0)
        strcat(http_response, response->body);
    return http_response;
}


void send_response(int client_fd, response_t *response)
{
    char *http_response = format_http_response(response);

    if (!http_response) {
        dprintf(client_fd, "%s", "HTTP/1.1 500 Internal Server Error\r\n"
            "Content-Type: text/plain\r\n\r\nInternal Server Error");
        return;
    }
    dprintf(client_fd, "%s", http_response);
    free(http_response);
}
