/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** b_init
*/

#include "game.h"
#include "functions.h"

button_t *take_o_button(int x, int y, char *path, int j)
{
    button_t *button = my_malloc(sizeof(button_t));

    button->pos.x = x;
    button->pos.y = y;
    if (j >= 5) {
        button->rect.width = 125;
        button->rect.height = 120;
    } else {
        button->rect.width = 450;
        button->rect.height = 100;
    }
    button->rect.left = 0;
    button->rect.top = 0;
    button->texture = sfTexture_createFromFile(path, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_setPosition(button->sprite, button->pos);
    return (button);
}

button_t *init_other_buttons(int j, int x)
{
    char *path[7] = {"ressources/b/b_on.png", "ressources/b/b_off.png",
    "ressources/b/b_high.png", "ressources/b/b_low.png",
    "ressources/b/b_menu.png", "ressources/b/b_sound.png",
    "ressources/b/b_arrow.png"};
    int pos[14] = {159, 330, 159, 644, 1312, 330, 1312, 643, 736, 893,
    322, 480, 1474, 480};

    return (take_o_button(pos[j], pos[j + 1], path[x], x));
}

button_t *take_button(int x, int y, char *path)
{
    button_t *button = my_malloc(sizeof(button_t));

    button->pos.x = x;
    button->pos.y = y;
    button->rect.width = 450;
    button->rect.height = 100;
    button->rect.left = 0;
    button->rect.top = 0;
    button->texture = sfTexture_createFromFile(path, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_setPosition(button->sprite, button->pos);
    return (button);
}

button_t **init_buttons(void)
{
    button_t **buttons = my_malloc(sizeof(button_t *) * 15);
    char *path[8] = {"ressources/b/b_new.png", "ressources/b/b_load.png",
        "ressources/b/b_settings.png", "ressources/b/b_help.png",
        "ressources/b/b_quit.png", "ressources/b/b_resume.png",
        "ressources/b/b_menu.png", "ressources/b/b_quit.png"};
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 215;

    for (i = 0; i < 4; i++, y += 150)
        buttons[i] = take_button(1275, y, path[i]);
    buttons[i] = take_button(1275, 920, path[i]);
    y = 380;
    for (i = 5; i < 8; i++, y += 200)
        buttons[i] = take_button(735, y, path[i]);
    for (i = 8; i < 15; i++, j += 2, x++) {
        buttons[i] = init_other_buttons(j, x);
    }
    return (buttons);
}