/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** free_response
*/

#include <response.h>
#include <stdlib.h>

void free_response(response_t *response)
{
    if (response->headers) {
        for (size_t i = 0; i < response->header_count; i++)
            free(response->headers[i]);
        free(response->headers);
    }
    free(response);
}
