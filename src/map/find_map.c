/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** find_map
*/

#include <map.h>
#include <string.h>

char *find_map(map_t **map, char *key, size_t length)
{
    for (size_t i = 0; i < length; ++i)
        if (strcmp(map[i]->key, key) == 0)
            return map[i]->value;
    return NULL;
}
