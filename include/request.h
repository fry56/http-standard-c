/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** request
*/

#pragma once

#include <method.h>
#include <stddef.h>
#include <stdbool.h>
#include <config.h>
#include "map.h"

typedef struct {
    char *path;
    struct route_params_s *route;
    char *body;
    method_t method;

    map *headers;
    map *params;
    map *cache;
} request_t;

bool parse_request(int sockfd, request_t *request);
void free_request(request_t *request);
