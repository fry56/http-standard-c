/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** find_route
*/
#include <regex.h>
#include "router.h"

route_s *find_route(list *router, const char *path, method_t method)
{
    regmatch_t matches[10];

    list_foreach(router, entry)
        if (regexec(&((route_s *)entry->value)->regex_pattern, path,
            10, matches, 0) == 0 && ((route_s *)entry->value)->method == method)
            return entry->value;
    return NULL;
}
