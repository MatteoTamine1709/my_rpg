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
#include <SFML/Audio/Music.h>
#include "functions.h"

void e_game(game_t *game, sfEvent event, sfVector2i pos)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        game->manage_index = 5;
        (*game->scenes[game->manage_index])(game);
    }
    if (game->player->inventory_open == 1 && game->player->in_shop == 0
    && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        handle_mouse_eventgame(pos, game);
    if (game->player->in_fight == 0) {
        if (event.type == sfEvtMouseButtonPressed &&
            game->player->stuck == 0) {
            game->player->destination_point.x = pos.x;
            game->player->destination_point.y = pos.y;
        }
        if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyE)) {
            game->player->stuck ^= 1;
            game->player->inventory_open ^= 1;
        }
    } else {
        event_fight(game, event);
    }
}

void e_breakt(game_t *game, sfEvent event, sfVector2i pos)
{
    if (735 < pos.x && pos.x < 1185 && 380 < pos.y && pos.y < 480) {
        (*game->b_anim[0])(game, game->buttons[5], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            (*game->b_anim[1])(game, game->buttons[5], 4, 900);
    }
    if (735 < pos.x && pos.x < 1185 && 580 < pos.y && pos.y < 680) {
        (*game->b_anim[0])(game, game->buttons[6], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            (*game->b_anim[1])(game, game->buttons[6], 0, 900);
            sfMusic_stop(game->music->game);
        }
    }
    if (735 < pos.x && pos.x < 1185 && 780 < pos.y && pos.y < 880) {
        (*game->b_anim[0])(game, game->buttons[7], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            (*game->b_anim[1])(game, game->buttons[7], 6, 900);
    }
}

void e_game_over(game_t *game, sfEvent event, sfVector2i pos)
{
    if (735 < pos.x && pos.x < 1185 && 780 < pos.y && pos.y < 880) {
        (*game->b_anim[0])(game, game->buttons[7], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            (*game->b_anim[1])(game, game->buttons[7], 6, 900);
    }
}

void e_tbc(game_t *game, sfEvent event, sfVector2i pos)
{
    if (735 < pos.x && pos.x < 1185 && 780 < pos.y && pos.y < 880) {
        (*game->b_anim[0])(game, game->buttons[7], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            (*game->b_anim[1])(game, game->buttons[7], 6, 900);
    }
}

void event_manager(game_t *game)
{
    sfEvent event;
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window->w);
    void(*manage_event[])(game_t *, sfEvent, sfVector2i) = {e_menu, e_load,
        e_settings, e_help, e_game, e_breakt, e_quit, e_game_over, e_tbc};

    if (game->manage_index != 4) {
        (*manage_event[game->manage_index])(game, event, pos);
    }
    while (game->manage_index == 4 &&
        sfRenderWindow_pollEvent(game->window->w, &event))
        (*manage_event[game->manage_index])(game, event, pos);
}