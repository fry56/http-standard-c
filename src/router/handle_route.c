/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** handle_route
*/

#include "router.h"
#include <stdio.h>

bool execute_route_logic(route_params_t *route, request_t *request, response_t *response)
{
    if (route->middleware) {
        if (!route->middleware(request, response))
            return false;
    }
    if (route->handler) {
        route->handler(request, response);
        return true;
    }
    response->status_code = NOT_IMPLEMENTED;
    response->body = "Not implemented";
    return false;
}

//void handle_route(int socketd, router_t *router)
//{
//    request_t request = {0};
//    response_t response = {0};
//    route_params_t *route = find_route(router, buffer);
//
//    if (route == NULL) {
//        char *reply = "HTTP/1.1 404 Not Found\nContent-Type: text/plain\n\nRoute not found";
//
//        dprintf(socketd, reply);
//        return;
//    }
//    if (execute_route_logic(route, &request, &response)) {
//        char response_text[1024];  // Construire une réponse basée sur `response`
//        snprintf(response_text, sizeof(response_text), "HTTP/1.1 200 OK\nContent-Type: text/plain\n\n%s", response.body);
//        write(newsockfd, response_text, strlen(response_text));
//    } else {
//        char *reply = "HTTP/1.1 404 Not Found\nContent-Type: text/plain\n\nRoute not found";
//        write(newsockfd, reply, strlen(reply));
//    }
//
//    close(newsockfd);
//}
