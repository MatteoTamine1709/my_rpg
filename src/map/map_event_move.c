/*
** EPITECH PROJECT, 2020
** test
** File description:
** main
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "functions.h"

int *move_effect(char *filepath, game_t *game)
{
    int *dest = load_effect(my_strcat(filepath, game->current_map), game);

    return (dest);
}

redirect_t *move_redirect(char *filepath, game_t *game)
{
    redirect_t *dest = load_redirect(my_strcat(filepath, game->current_map),
    game);

    return (dest);
}

npc_t *move_npc(char *filepath, game_t *game)
{
    npc_t *dest = load_npc(my_strcat(filepath, game->current_map), game);

    return (dest);
}

prop_t *move_props(char *filepath, game_t *game)
{
    prop_t *dest = load_props(my_strcat(filepath, game->current_map), game);

    return (dest);
}

light_t *move_light(char *filepath, game_t *game)
{
    light_t *dest = load_light(my_strcat(filepath, game->current_map), game);

    return (dest);
}