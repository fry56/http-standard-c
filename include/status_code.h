/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** status_code
*/

#pragma once

typedef enum status_code_e {
    NOT_FOUND = 404,
    OK = 200,
    CREATED = 201,
    NO_CONTENT = 204,
    BAD_REQUEST = 400,
    UNAUTHORIZED = 401,
    FORBIDDEN = 403,
    INTERNAL_SERVER_ERROR = 500,
    NOT_IMPLEMENTED = 501,
    SERVICE_UNAVAILABLE = 503
} status_code_t;

typedef struct {
    status_code_t code;
    const char *message;
} status_code_info_t;

const status_code_info_t status_codes[] = {
    {OK, "OK"},
    {CREATED, "Created"},
    {NO_CONTENT, "No Content"},
    {BAD_REQUEST, "Bad Request"},
    {UNAUTHORIZED, "Unauthorized"},
    {FORBIDDEN, "Forbidden"},
    {NOT_FOUND, "Not Found"},
    {INTERNAL_SERVER_ERROR, "Internal Server Error"},
    {NOT_IMPLEMENTED, "Not Implemented"},
    {SERVICE_UNAVAILABLE, "Service Unavailable"},
    {0, NULL}
};
