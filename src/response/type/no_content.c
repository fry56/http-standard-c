/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** no_content
*/

#include <response.h>
#include <string.h>

response_t *new_no_content(response_t *response)
{
    response->status_code = 204;
//    response->body = message;
//    response->body_length = strlen(message);
//    add_header_response(response, "Content-Type: text/plain");
    return response;
}
