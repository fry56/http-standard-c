/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** free_request
*/

#include <request.h>
#include <stdlib.h>

void free_request(request_t *request)
{
    if (request->path)
        free(request->path);
    if (request->body)
        free(request->body);
    for (size_t i = 0; i < request->param_count; i++) {
        free(request->params[i].key);
        free(request->params[i].value);
    }
    if (request->headers) {
        for (size_t i = 0; i < request->header_count; i++) {
            free(request->headers[i]);
        }
        free(request->headers);
    }
}
