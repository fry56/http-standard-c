/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** handle_request
*/

#include <request.h>
#include <response.h>
#include <router.h>
#include <unistd.h>
#include <stdio.h>

void handle_request(int socketFd, router_t *router)
{
    request_t request = {0};
    response_t *response;

    if (!parse_request(socketFd, &request)) {
        printf("Error parsing request\n");
        close(socketFd);
        return;
    }
    response = handle_route(router, &request);
    if (response == NULL)
        return;
    send_response(socketFd, response);
    free_response(response);
}
