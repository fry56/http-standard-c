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


static const char *get_status_message(status_code_t status_code)
{
    for (const status_code_info_t *info = status_codes;
        info->message != NULL; info++)
        if (info->code == status_code)
            return info->message;
    return "Unknown";
}

static size_t get_response_length(response_t *response)
{
    size_t length = 0;

    length += snprintf(NULL, 0, "HTTP/1.1 %d %s\r\n",
        response->status_code,
        get_status_message(response->status_code));
    for (size_t i = 0; i < response->header_count; i++)
        length += strlen(response->headers[i]->key) +
            strlen(response->headers[i]->value) + 4;
    length += 2;
    if (response->body && response->body_length > 0)
        length += response->body_length;
    return length + 2;
}

static void add_content_length_header(response_t *response)
{
    char *str = malloc(20);

    if (!str) {
        fprintf(stderr, "Failed to allocate "
            "memory for Content-Length header\n");
        return;
    }
    sprintf(str, "%zu", response->body_length);
    add_map(&response->headers, "Content-Length",
        str, &response->header_count);
}

static char *format_http_response(response_t *response)
{
    size_t estimated_length = get_response_length(response);
    char *http_response = malloc(estimated_length + 1);
    size_t offset;

    if (!http_response) {
        fprintf(stderr, "Failed to allocate memory for HTTP response\n");
        return NULL;
    }
    offset = snprintf(http_response, estimated_length,
        "HTTP/1.1 %d %s\r\n",
        response->status_code, get_status_message(response->status_code));
    for (size_t i = 0; i < response->header_count; i++)
        offset += sprintf(http_response + offset, "%s: %s\r\n",
            response->headers[i]->key, response->headers[i]->value);
    strcat(http_response + offset, "\r\n");
    if (response->body && response->body_length > 0)
        strcat(http_response + offset, response->body);
    return http_response;
}

void send_response(int client_fd, response_t *response)
{
    char *http_response;

    add_content_length_header(response);
    http_response = format_http_response(response);
    if (!http_response) {
        if (response->status_code != INTERNAL_SERVER_ERROR) {
            new_internal_server_error(response,
                "Failed to format HTTP response");
            send_response(client_fd, response);
        }
        return;
    }
    dprintf(client_fd, "%s", http_response);
    free(http_response);
}
