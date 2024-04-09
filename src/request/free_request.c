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
    free_map(request->params, request->param_count);
    free_map(request->headers, request->header_count);
}
