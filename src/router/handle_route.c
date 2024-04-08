/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** handle_route
*/

#include <router.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

response_t *handle_route(router_t *router, request_t *request)
{
    route_params_t *route = find_route(router, request->path);
    response_t *response = calloc(1, sizeof(response_t));

    if (response == NULL)
        return NULL;
    if (route == NULL) {
        response->status_code = NOT_FOUND;
        response->body = "Not found";
        return response;
    }
    request->route = route;
    extract_params(request);
    execute_route_logic(route, request, response);
    return response;
}
