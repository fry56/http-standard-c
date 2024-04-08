/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** internal_server_error
*/

#include <response.h>
#include <string.h>

response_t *new_internal_server_error(response_t *response, char *message)
{
    response->status_code = 500;
    response->body = message;
    response->body_length = strlen(message);
    add_header_response(response, "Content-Type: text/plain");
    return response;
}
