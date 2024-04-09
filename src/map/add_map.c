/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** add_map
*/

#include <stdlib.h>
#include <map.h>
#include <string.h>

map_t *add_map(map_t ***map, char *key, char *value, size_t *length)
{
    map_t **new_map = realloc(*map, (*length + 1) * sizeof(map_t *));
    map_t *new_map_elem;

    if (new_map == NULL)
        return NULL;
    new_map_elem = malloc(sizeof(map_t));
    if (new_map_elem == NULL)
        return NULL;
    new_map_elem->key = strdup(key);
    new_map_elem->value = strdup(value);
    new_map[*length] = new_map_elem;
    *length += 1;
    *map = new_map;
    return new_map_elem;
}

