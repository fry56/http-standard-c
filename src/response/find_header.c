/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** find_header
*/

#include <string.h>
#include <response.h>

char *find_header_value_response(char *header, response_t *response)
{
    for (size_t i = 0; i < response->header_count; i++) {
        if (strstr(response->headers[i], header) != NULL) {
            return response->headers[i] + strlen(header) + 2;
        }
    }
    return NULL;
}
