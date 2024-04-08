/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** main
*/
#include <stdio.h>
#include <stdlib.h>
#include <router.h>
#include <response.h>
#include <string.h>

int main() {
    // Setup a sample response structure
    response_t response = {
            .status_code = 200,  // HTTP status code
            .header_count = 2,   // Number of headers
            .body = "Hello, World!",  // Response body
            .body_length = strlen("Hello, World!")  // Length of the body
    };

    // Allocate memory for headers
    response.headers = malloc(response.header_count * sizeof(char *));
    if (!response.headers) {
        fprintf(stderr, "Failed to allocate memory for headers\n");
        return EXIT_FAILURE;
    }

    // Set headers
    response.headers[0] = strdup("Content-Type: text/html; charset=UTF-8");
    response.headers[1] = strdup("Connection: close");

    // Format the HTTP response
    char *http_response = format_http_response(&response);
    if (http_response) {
        printf("Formatted HTTP Response:\n%s", http_response);
        free(http_response);
    } else {
        fprintf(stderr, "Failed to format HTTP response\n");
    }

    // Clean up allocated memory
    for (size_t i = 0; i < response.header_count; i++) {
        free(response.headers[i]);
    }
    free(response.headers);

    return EXIT_SUCCESS;
}

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