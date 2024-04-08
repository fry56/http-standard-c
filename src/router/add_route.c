/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** add_route
*/

#include <router.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <regex.h>

static void parse_and_store_param_names(const char *template_path, char param_names[10][256], size_t *param_count) {
    const char *cursor = template_path;
    size_t name_len;

    *param_count = 0;
    while (*cursor) {
        if (*cursor != ':') {
            cursor++;
            continue;
        }
        name_len = 0;
        cursor++;
        while (*cursor != '/' && *cursor != '\0' && name_len < 255)
            param_names[*param_count][name_len++] = *cursor++;
        param_names[*param_count][name_len] = '\0';
        (*param_count)++;
    }
}

static void compile_regex_for_route(route_params_t *route) {
    char regex_pattern[1024];
    const char *src = route->template_path;
    char *dest = regex_pattern;

    *dest++ = '^';
    while (*src) {
        if (*src == ':') {
            strcpy(dest, "([^/]+)");
            dest += strlen("([^/]+)");
            while (*src && *src != '/') src++;
        } else {
            *dest++ = *src++;
        }
    }
    *dest++ = '$';
    *dest = '\0';
    if (regcomp(&route->regex_pattern, regex_pattern, REG_EXTENDED) != 0)
        fprintf(stderr, "Failed to compile regex: %s\n", regex_pattern);
}

route_entry_t *add_route(router_t *router, route_config_t config) {
    route_entry_t *new_entry = malloc(sizeof(route_entry_t));

    if (new_entry == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    new_entry->params.template_path = strdup(config.template_path);
    new_entry->params.method = config.method;
    new_entry->params.middleware = config.middleware;
    new_entry->params.handler = config.handler;
    parse_and_store_param_names(config.template_path,
                                new_entry->params.param_names,
                                &new_entry->params.param_count);
    compile_regex_for_route(&new_entry->params);
    TAILQ_INSERT_TAIL(router, new_entry, entries);
    return new_entry;
}
