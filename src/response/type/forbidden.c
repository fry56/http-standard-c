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
    response->content_type = "text/plain";
    return response;
}
