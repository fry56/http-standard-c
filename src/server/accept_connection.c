#include <netinet/in.h>

/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** accept_connexion
*/

int accept_connection(int server_fd) {
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    return accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
}
