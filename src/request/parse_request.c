/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** parse_request
*/
#include <request.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <config.h>

//status_code_t string_to_method(const char *method) {
//    for (int i = 0; status_codes[i].message != NULL; i++) {
//        if (atoi(method) == (int)status_codes[i].code)
//            return i;
//    }
//    return INVALID_METHOD;
//}

method_t string_to_method(const char *method) {
    for (int i = 0; methods[i].string != NULL; i++) {
        if (strcmp(methods[i].string, method) == 0)
            return methods[i].method;
    }
    return INVALID_METHOD;
}

bool parse_request(int sockfd, request_t *request) {
    char buffer[BUFFER_SIZE];
    char *saveptr;
    char *method;
    char *path;
    ssize_t bytes_read = read(sockfd, buffer, sizeof(buffer) - 1);

    if (bytes_read <= 0) {
        fprintf(stderr, "Failed to read from socket or connection closed by client.\n");
        return false;
    }
    buffer[bytes_read] = '\0';
    method = strtok_r(buffer, " ", &saveptr);
    path = strtok_r(NULL, " ", &saveptr);
    request->method = string_to_method(method);
    request->path = strdup(path);
    request->body = strdup(saveptr);
    return true;
}
