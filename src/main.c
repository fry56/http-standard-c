/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** main
*/
#include <router.h>
#include <unistd.h>
#include <server.h>

#define PORT 8080

void handler(request_t *request, response_t *response) {
    char *uuid = "76ba651f-adfd-4b2d-9dd2-db3bd5ee9c3d";
    char *value = find_param(request, "teamUuid");

    if (strcmp(uuid, value) != 0) {
        new_not_found(response, "Team not found");
        return;
    }
    new_ok(response, "Team found");
}

int main() {
    router_t router;

    init_router(&router);
    add_route(&router, (route_config_t){"/teams/:teamUuid/users", GET, NULL, handler});
    start_server(PORT, &router);
    return 0;
}