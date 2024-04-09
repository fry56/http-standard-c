/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** free_response
*/

#include <response.h>
#include <stdlib.h>
#include <map.h>

void free_response(response_t *response)
{
    free_map(response->headers, response->header_count);
    free(response);
}
