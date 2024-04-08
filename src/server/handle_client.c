/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** handle_client
*/

#include <stdio.h>
#include "router.h"
#include <string.h>
#include <regex.h>

void convert_path_to_regex(const char *template_path, char *regex_buffer) {
    const char *cursor = template_path;

    *regex_buffer = '^';
    regex_buffer++;
    while (*cursor) {
        if (*cursor == ':') {
            strcat(regex_buffer, "([^/]+)");
            regex_buffer += strlen("([^/]+)");
            cursor++;
            while (*cursor && *cursor != '/') cursor++;
        } else {
            *regex_buffer++ = *cursor++;
        }
    }
    *regex_buffer++ = '$';
    *regex_buffer = '\0';
}

void extract_params(request_t *request) {
    char regex_pattern[1024] = {0};
    regmatch_t matches[10];
    regex_t regex;
    char found_param[256];

    convert_path_to_regex(request->route->template_path, regex_pattern);
    if (regcomp(&regex, regex_pattern, REG_EXTENDED) != 0) {
        fprintf(stderr, "Failed to compile regex\n");
        return;
    }
    if (regexec(&regex, request->path, 10, matches, 0) == 0) {
        for (int i = 1; i < 10 && matches[i].rm_so != -1; i++) {
            found_param[0] = '\0';
            strncpy(found_param, request->path + matches[i].rm_so, matches[i].rm_eo - matches[i].rm_so);
            found_param[matches[i].rm_eo - matches[i].rm_so] = '\0';
            printf("Found param: %s\n", found_param);
            request->params[request->param_count].key = strdup(request->route->param_names[i - 1]);
            request->params[request->param_count].value = strdup(found_param);
            request->param_count++;
        }
    }
    regfree(&regex);
}
