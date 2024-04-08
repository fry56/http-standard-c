/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** start_server
*/

#include <server.h>
#include <stdio.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <unistd.h>

int start_server(int port, router_t *router) {
    int server_fd = create_server_socket(port);
    struct sockaddr_in client_address;
    socklen_t client_address_len;
    int client_fd = 0;

    if (server_fd == -1)
        return 84;
    printf("Server started on port %d\n", port);
    while (true) {
        client_address_len = sizeof(client_address);
        client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_len);

        if (client_fd == -1) {
            printf("Failed to accept connection");
            continue;
        }
        handle_request(client_fd, router);
    }
    close(server_fd);
    return 0;
}
