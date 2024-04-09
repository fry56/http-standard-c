/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** parse_request
*/
#include <request.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <config.h>
#include <ctype.h>

static method_t string_to_method(const char *method)
{
    for (int i = 0; methods[i].string != NULL; i++) {
        if (strcmp(methods[i].string, method) == 0)
            return methods[i].method;
    }
    return INVALID_METHOD;
}

static void trim_whitespace(char **str)
{
    char *s = *str;
    char *end;

    while (isspace((unsigned char)*s))
        s++;
    *str = s;
    end = s + strlen(s) - 1;
    while (end > s && isspace((unsigned char)*end)) {
        *end = '\0';
        end--;
    }
}

static void process_header_line(char *line, request_t *request)
{
    char *colon = strchr(line, ':');
    char *key;
    char *value;

    if (!colon)
        return;
    *colon = '\0';
    key = line;
    value = colon + 1;
    trim_whitespace(&key);
    trim_whitespace(&value);
    add_map(&request->headers, key, value, &request->header_count);
}

void parse_headers(char *header_str, request_t *request)
{
    char *line;
    char *saveptr_header;

    line = strtok_r(header_str, "\r\n", &saveptr_header);
    while (line != NULL && request->header_count < HEADER_ARRAY_SIZE) {
        process_header_line(line, request);
        line = strtok_r(NULL, "\r\n", &saveptr_header);
    }
}

bool parse_request(int sockfd, request_t *request)
{
    char buffer[BUFFER_SIZE] = {0};
    char *saveptr;
    char *method;
    char *path;
    ssize_t bytes_read = read(sockfd, buffer, sizeof(buffer) - 1);

    if (bytes_read <= 0) {
        fprintf(stderr, "Failed to read from socket"
            " or connection closed by client.\n");
        return false;
    }
    parse_headers(buffer, request);
    buffer[bytes_read] = '\0';
    method = strtok_r(buffer, " ", &saveptr);
    path = strtok_r(NULL, " ", &saveptr);
    request->method = string_to_method(method);
    request->path = strdup(path);
    request->body = strdup(saveptr);
    return true;
}
