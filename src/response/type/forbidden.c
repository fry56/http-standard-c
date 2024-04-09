/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** forbidden
*/

#include <response.h>
#include <string.h>

response_t *new_forbidden(response_t *response, char *message)
{
    response->status_code = 403;
    response->body = message;
    response->body_length = strlen(message);
    add_map(&response->headers, "Content-Type",
        "text/plain", &response->header_count);
    return response;
}
