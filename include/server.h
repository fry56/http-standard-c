/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** server
*/

#pragma once

#include "router.h"
#include <netinet/in.h>

typedef struct server_s {
    int socketFd;
    struct sockaddr_in address;
    map *cache;
    router_t *router;
} server_t;

server_t *create_server(int port, router_t *router);
int start_server(int port, router_t *router);
void handle_request(int clientFd, server_t *server);
router_t *init_router(router_t *router);
void convert_path_to_regex(const char *template_path, char *regex_buffer);
