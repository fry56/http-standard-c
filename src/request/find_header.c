/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** find_header
*/

#include <request.h>
#include <string.h>

char *find_header_value_request(char *header, request_t *request)
{
    for (size_t i = 0; i < request->header_count; i++) {
        if (strstr(request->headers[i], header) != NULL) {
            return request->headers[i] + strlen(header) + 2;
        }
    }
    return NULL;
}
