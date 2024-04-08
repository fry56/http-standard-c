/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** server
*/

#pragma once

#include "router.h"

int create_server_socket(int port);
int start_server(int port, router_t *router);
void handle_request(int socketFd, router_t *router);
router_t *init_router(router_t *router);
void convert_path_to_regex(const char *template_path, char *regex_buffer);
