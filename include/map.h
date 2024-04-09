/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** header
*/

#pragma once

#include <stdlib.h>

typedef struct map_s {
    char *key;
    char *value;
} map_t;

map_t *add_map(map_t ***map, char *key, char *value, size_t *length);
char *find_map(map_t **map, char *key, size_t length);
void free_map(map_t **map, size_t length);
