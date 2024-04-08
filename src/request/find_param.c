/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** find_param
*/

#include <request.h>

char *find_param(request_t *request, char *param)
{
    for (size_t i = 0; i < request->param_count; ++i)
        if (strcmp(request->params[i].key, param) == 0)
            return request->params[i].value;
    return NULL;
}
