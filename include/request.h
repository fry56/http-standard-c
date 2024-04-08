/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** request
*/

#pragma once

#include "method.h"
#include <stddef.h>

typedef struct {
    char *key;
    char *value;
} param_t;

typedef struct {
    char *path;
    struct route_params_s *route;
    char *body;
    method_t method;
    char **headers;
    size_t header_count;
    param_t params[10];
    size_t param_count;
} request_t;
