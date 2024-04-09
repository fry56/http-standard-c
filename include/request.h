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
#include <map.h>

typedef struct {
    char *path;
    struct route_params_s *route;
    char *body;
    method_t method;

    map_t **headers;
    size_t header_count;

    map_t **params;
    size_t param_count;
} request_t;

bool parse_request(int sockfd, request_t *request);
void free_request(request_t *request);
