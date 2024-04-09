/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** free_map
*/

#include <stdlib.h>
#include <map.h>

void free_map(map_t **map, size_t length)
{
    if (map == NULL)
        return;
    for (size_t i = 0; i < length; ++i) {
        free(map[i]->key);
        free(map[i]->value);
        free(map[i]);
    }
    free(map);
}
