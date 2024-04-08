/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** bad_request
*/

#include <response.h>
#include <string.h>

response_t *new_bad_request(response_t *response, char *message)
{
    response->status_code = 400;
    response->body = message;
    response->body_length = strlen(message);
    add_header_response(response, "Content-Type: text/plain");
    return response;
}
