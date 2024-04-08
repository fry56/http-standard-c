/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** free_router
*/

#include <router.h>
#include <stdlib.h>

void free_router(router_t *router)
{
    route_entry_t *entry;

    if (router == NULL)
        return;
    entry = TAILQ_FIRST(router);
    while (entry != NULL) {
        TAILQ_REMOVE(router, entry, entries);
        free(entry->params.template_path);
        regfree(&entry->params.regex_pattern);
        free(entry);
        entry = TAILQ_FIRST(router);
    }
}
