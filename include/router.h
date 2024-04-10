/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** path
*/

#pragma once

#include <method.h>
#include <request.h>
#include <response.h>
#include <sys/queue.h>
#include <regex.h>
#include <stdbool.h>
#include <config.h>
#include <list.h>

typedef struct route_s {
    char *template_path;
    regex_t regex_pattern;
    char param_names[PARAM_ARRAY_SIZE][PARAM_SIZE];
    size_t param_count;
    method_t method;
    bool (*middleware)(request_t *, response_t *);
    void (*handler)(request_t *, response_t *);
} route_s;

typedef struct {
    char *template_path;
    method_t method;
    bool (*middleware)(request_t *, response_t *);
    void (*handler)(request_t *, response_t *);
} route_config_t;

route_s *add_route(list *router, route_config_t config);
route_s *find_route(list *router, const char *path);
response_t *handle_route(list *router, request_t *request);
void extract_params(request_t *request);
