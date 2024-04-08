/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** find_route
*/
#include <regex.h>
#include "router.h"

route_params_t *find_route(router_t *router, const char *path)
{
    route_entry_t *entry;
    regmatch_t matches[10];

    TAILQ_FOREACH(entry, router, entries)
        if (regexec(&entry->params.regex_pattern, path, 10, matches, 0) == 0)
            return &entry->params;
    return NULL;
}
