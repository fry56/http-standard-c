/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** find_route
*/
#include <regex.h>
#include "router.h"

route_s *find_route(list *router, const char *path)
{
    regmatch_t matches[10];

    list_foreach(router, entry)
        if (regexec(&((route_s *)entry->value)->regex_pattern, path, 10, matches, 0) == 0)
            return entry->value;
    return NULL;
}
