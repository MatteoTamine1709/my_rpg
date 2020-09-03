/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** button_animations
*/

#include "game.h"
#include "functions.h"

void b_overed(game_t *g, button_t *button, int i, int y)
{
    button->rect.left = y;
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfRenderWindow_drawSprite(g->window->w, button->sprite, NULL);
}

void b_clicked(game_t *g, button_t *button, int i, int y)
{
    button->rect.left = y;
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfRenderWindow_drawSprite(g->window->w, button->sprite, NULL);
    sfRenderWindow_display(g->window->w);
    sound_click();
    g->manage_index = i;
    button->rect.left = 0;
    sfSprite_setTextureRect(button->sprite, button->rect);
}

void create_animations(game_t *game)
{
    game->b_anim = my_malloc(sizeof(b_anim_t) * 2);
    game->b_anim[0] = b_overed;
    game->b_anim[1] = b_clicked;
}