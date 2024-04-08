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

typedef struct route_params_s {
    char *template_path;
    regex_t regex_pattern;
    char param_names[PARAM_ARRAY_SIZE][PARAM_SIZE];
    size_t param_count;
    method_t method;
    bool (*middleware)(request_t *, response_t *);
    void (*handler)(request_t *, response_t *);
} route_params_t;

typedef struct {
    char *template_path;
    method_t method;
    bool (*middleware)(request_t *, response_t *);
    void (*handler)(request_t *, response_t *);
} route_config_t;

typedef struct route_entry {
    route_params_t params;
    TAILQ_ENTRY(route_entry) entries;
} route_entry_t;

typedef TAILQ_HEAD(router, route_entry) router_t;

route_entry_t *add_route(router_t *router, route_config_t config);
route_params_t *find_route(router_t *router, const char *path);
response_t *handle_route(router_t *router, request_t *request);
void extract_params(request_t *request);
void free_router(router_t *router);
