/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** responce
*/

#pragma once

#include <stddef.h>
#include "status_code.h"

typedef struct {
    status_code_t status_code;
    char **headers;
    size_t header_count;
    char *body;
    size_t body_length;
} response_t;

char *format_http_response(const response_t *response);