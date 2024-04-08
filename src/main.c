/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** main
*/
#include <stdio.h>
#include <stdlib.h>
#include <router.h>
#include <netinet/in.h>
#include <unistd.h>
#include <server.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handler(request_t *request, response_t *response) {
    char *uuid = "76ba651f-adfd-4b2d-9dd2-db3bd5ee9c3d";
    char *value = find_param(request, "teamUuid");
    printf("Team uuid: %s\n", value);

    add_header_response(response, "Content-Type: text/plain");
    if (strcmp(uuid, value) != 0) {
        response->status_code = BAD_REQUEST;
        response->body = "Invalid Uuid";
        response->body_length = strlen(response->body);
    }
    response->status_code = OK;
}

int main() {
    router_t router;
    TAILQ_INIT(&router);

    add_route(&router, (route_config_t){"/teams/:teamUuid/users", GET, NULL, handler});

    start_server(PORT, &router);

    return 0;
}

//int main() {
//    int server_fd, new_socket;
//    struct sockaddr_in address;
//    int addrlen = sizeof(address);
//
//    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
//        perror("socket failed");
//        exit(EXIT_FAILURE);
//    }
//
//    address.sin_family = AF_INET;
//    address.sin_addr.s_addr = INADDR_ANY;
//    address.sin_port = htons(PORT);
//
//    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
//        perror("bind failed");
//        exit(EXIT_FAILURE);
//    }
//
//    if (listen(server_fd, 3) < 0) {
//        perror("listen");
//        exit(EXIT_FAILURE);
//    }
//
//    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
//        perror("accept");
//        exit(EXIT_FAILURE);
//    }
//
//    request_t request;
//    if (parse_request(new_socket, &request)) {
////        printf("Method: %d\n", request.method);
//        printf("Path: %s\n", request.path);
//        printf("Body: %s\n", request.body);
//    }
//
//    return 0;
//}

//int main() {
//    response_t response = {
//            .status_code = 200,  // HTTP status code
//            .header_count = 2,   // Number of headers
//            .body = "Hello, World!",  // Response body
//            .body_length = strlen("Hello, World!")  // Length of the body
//    };
//
//    response.headers = malloc(response.header_count * sizeof(char *));
//    if (!response.headers) {
//        fprintf(stderr, "Failed to allocate memory for headers\n");
//        return EXIT_FAILURE;
//    }
//
//    response.headers[0] = strdup("Content-Type: text/html; charset=UTF-8");
//    response.headers[1] = strdup("Connection: close");
//
////    char *http_response = format_http_response(&response);
////    if (http_response) {
////        printf("Formatted HTTP Response:\n%s", http_response);
////        free(http_response);
////    } else {
////        fprintf(stderr, "Failed to format HTTP response\n");
////    }
////
////    for (size_t i = 0; i < response.header_count; i++) {
////        free(response.headers[i]);
////    }
////    free(response.headers);
////
////    return EXIT_SUCCESS;
//}

//int main() {
//    router_t router;
//    TAILQ_INIT(&router);
//
//    add_route(&router, (route_config_t){"/teams/:teamUuid/users", GET, NULL, NULL});
//
//    route_params_t *matched_route = find_route(&router, "/teams/1234/users");
//
////    while ()
//
//    if (matched_route == NULL) {
//        printf("No route found\n");
//        return 1;
//    }
//
//    request_t request = {0};
//    request.path = "/teams/1234/users";
//    request.route = matched_route;
//
//    extract_params(&request);
//
//    printf("Extracted Parameters:\n");
//    for (size_t i = 0; i < request.param_count; i++) {
//        printf("Key: %s, Value: %s\n", request.params[i].key, request.params[i].value);
//    }
//}