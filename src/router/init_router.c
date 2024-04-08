/*
** EPITECH PROJECT, 2024
** http-standard-c
** File description:
** init_router
*/

#include <router.h>

router_t *init_router(router_t *router) {
    TAILQ_INIT(router);
    return router;
}
