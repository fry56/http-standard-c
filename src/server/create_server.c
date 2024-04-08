/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** create_server
*/

#include <netinet/in.h>

int create_server_socket(int port) {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1)
        return -1;
    listen(server_fd, 10);
    return server_fd;
}
