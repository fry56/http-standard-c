/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** free_response
*/

#include <response.h>
#include <stdlib.h>
#include <xml.h>

void free_response(response_t *response)
{
    map_foreach(response->headers, elem)
        free(elem->key);
    free(response->headers);
    if (response->body != NULL)
        xml_free(response->body);
    free(response);
}
