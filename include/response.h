/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** responce
*/

#pragma once

#include <stddef.h>
#include <status_code.h>
#include <config.h>

typedef struct {
    status_code_t status_code;
    char **headers;
    char *content_type;
    size_t header_count;
    char *body;
    size_t body_length;
} response_t;

void send_response(int client_fd, response_t *response);
void add_header_response(response_t *response, char *header);

response_t *new_service_unavailable(response_t *response, char *message);
response_t *new_bad_request(response_t *response, char *message);
response_t *new_not_found(response_t *response, char *message);
response_t *new_ok(response_t *response, char *message);
response_t *new_created(response_t *response, char *message);
response_t *new_no_content(response_t *response);
response_t *new_unauthorized(response_t *response, char *message);
response_t *new_forbidden(response_t *response, char *message);
response_t *new_conflict(response_t *response, char *message);
response_t *new_not_implemented(response_t *response, char *message);
response_t *new_internal_server_error(response_t *response, char *message);
