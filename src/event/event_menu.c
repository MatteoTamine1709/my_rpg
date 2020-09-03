/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** event_menu
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Audio/Music.h>
#include "functions.h"

void set_menu(game_t *game)
{
    game->buttons[0]->rect.left = 0;
    game->buttons[1]->rect.left = 0;
    game->buttons[2]->rect.left = 0;
    game->buttons[3]->rect.left = 0;
    game->buttons[4]->rect.left = 0;
    sfSprite_setTextureRect(game->buttons[0]->sprite, game->buttons[0]->rect);
    sfSprite_setTextureRect(game->buttons[1]->sprite, game->buttons[1]->rect);
    sfSprite_setTextureRect(game->buttons[2]->sprite, game->buttons[2]->rect);
    sfSprite_setTextureRect(game->buttons[3]->sprite, game->buttons[3]->rect);
    sfSprite_setTextureRect(game->buttons[4]->sprite, game->buttons[4]->rect);
}

void history_anim(game_t *game)
{
    sfTexture *t = sfTexture_createFromFile("ressources/history.jpg", NULL);
    sfSprite *sprite = sfSprite_create();
    sfIntRect rect = {0, 0, 1920, 1080};
    sfTime time = sfSeconds(0.2);
    int i = 0;

    sfSprite_setTexture(sprite, t, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    while (1) {
        sfRenderWindow_drawSprite(game->window->w, sprite, NULL);
        sfRenderWindow_display(game->window->w);
        if (sfKeyboard_isKeyPressed(sfKeyX) == sfTrue) {
            i++;
            rect.left += 1920;
            sfSprite_setTextureRect(sprite, rect);
        }
        if (i == 3)
            break;
        sfSleep(time);
    }
}

void e_menu1(game_t *game, sfVector2i pos)
{
    if (1275 < pos.x && pos.x < 1725 && 215 < pos.y && pos.y < 315) {
        (*game->b_anim[0])(game, game->buttons[0], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            (*game->b_anim[1])(game, game->buttons[0], 4, 900);
            history_anim(game);
            sfMusic_stop(game->music->menu);
        }
    }
    if (1275 < pos.x && pos.x < 1725 && 365 < pos.y && pos.y < 465) {
        (*game->b_anim[0])(game, game->buttons[1], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            (*game->b_anim[1])(game, game->buttons[1], 4, 900);
    }
    if (1275 < pos.x && pos.x < 1725 && 515 < pos.y && pos.y < 615) {
        (*game->b_anim[0])(game, game->buttons[2], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            (*game->b_anim[1])(game, game->buttons[2], 2, 900);
    }
}

void e_menu2(game_t *game, sfVector2i pos)
{
    if (1275 < pos.x && pos.x < 1725 && 665 < pos.y && pos.y < 765) {
        (*game->b_anim[0])(game, game->buttons[3], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            (*game->b_anim[1])(game, game->buttons[3], 3, 900);
    }
    if (1275 < pos.x && pos.x < 1725 && 920 < pos.y && pos.y < 1020) {
        (*game->b_anim[0])(game, game->buttons[4], 0, 450);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            (*game->b_anim[1])(game, game->buttons[4], 6, 900);
        }
    }
}

void e_menu(game_t *game, sfEvent event, sfVector2i pos)
{
    set_menu(game);
    e_menu1(game, pos);
    e_menu2(game, pos);
}