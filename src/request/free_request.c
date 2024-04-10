/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** free_request
*/

#include <request.h>
#include <stdlib.h>
#include <map.h>

void free_request(request_t *request)
{
    map_foreach(request->params, elem) {
        free(elem->key);
        free(elem->value);
    }
    free(request->params);
    map_foreach(request->headers, elem) {
        free(elem->value);
        free(elem->key);
    }
    free(request->headers);
}
