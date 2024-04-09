/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** main
*/
#include <router.h>
#include <unistd.h>
#include <server.h>
#include <stdio.h>
#include <map.h>

#define PORT 8080

void handler(request_t *request, response_t *response) {
    char *uuid = "76ba651f-adfd-4b2d-9dd2-db3bd5ee9c3d";
    char *value = find_map(request->params, "teamUuid", request->param_count);

    printf("Value: %s\n", value);
    printf("count: %zu\n", request->param_count);

    if (value == NULL) {
        new_not_found(response, "Team not found");
        return;
    }

    if (strcmp(uuid, value) != 0) {
        new_not_found(response, "Team not found");
        return;
    }
    new_ok(response, "Team found");
}

bool middleware(request_t *request, response_t *response UNUSED) {
    const char *uuid = "76ba651f-adfd-4b2d-9dd2-db3bd5ee9c3d";
    const char *value = find_map(request->headers, "x-user-uuid", request->header_count);

    printf("Header: %zu\n", request->header_count);

    for (size_t i = 0; i < request->header_count; ++i) {
        printf("Header: %s\n", request->headers[i]->key);
    }

    printf("Value: %s\n", value);
    if (value == NULL || strcmp(value, uuid) != 0) {
        new_unauthorized(response, "Unauthorized");
        return false;
    }
    return true;
}

int main() {
    router_t router;

    init_router(&router);
    add_route(&router, (route_config_t){"/teams/:teamUuid/users", GET, NULL, handler});
    start_server(PORT, &router);
    return 0;
}