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
    param_t params[PARAM_ARRAY_SIZE];
    size_t param_count;
} request_t;

bool parse_request(int sockfd, request_t *request);
char *find_param(request_t *request, char *param);
char *find_header_value_request(char *header, request_t *request);
void free_request(request_t *request);
