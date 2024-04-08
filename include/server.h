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
int accept_connection(int server_fd);
void convert_path_to_regex(const char *template_path, char *regex_buffer);
//void extract_params(const char *template_path, const char *actual_path, request_t *request);
