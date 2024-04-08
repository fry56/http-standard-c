/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** no_content
*/

#include <response.h>

response_t *new_no_content(response_t *response)
{
    response->status_code = 204;
    return response;
}
