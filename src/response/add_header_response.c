/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** add_header_response
*/

#include <response.h>
#include <stdlib.h>
#include <string.h>

void add_header_response(response_t *response, char *header)
{
    size_t header_count = response->header_count + 1;

    response->headers = realloc(response->headers, header_count * 8);
    if (response->headers == NULL)
        return;
    response->headers[header_count - 1] = strdup(header);
    response->header_count = header_count;
}
