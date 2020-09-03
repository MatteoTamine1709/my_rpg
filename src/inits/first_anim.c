/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** first_anim
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "functions.h"
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/Audio/Music.h>
#include <stddef.h>

void display_first_anim(game_t *game, sfSprite *sback, sfSprite *gif)
{
    sfRenderWindow_clear(game->window->w, sfColor_fromRGB(30, 30, 30));
    sfRenderWindow_drawSprite(game->window->w, sback, NULL);
    sfRenderWindow_drawSprite(game->window->w, gif, NULL);
    sfRenderWindow_display(game->window->w);
}

sfIntRect change_rect(sfIntRect rect, sfSprite *gif, int i, sfMusic *animo)
{
    if (i == 7)
        sfMusic_play(animo);
    if (rect.left == 7500) {
        rect.left = 0;
        rect.top += 450;
    } else
        rect.left += 500;
    sfSprite_setTextureRect(gif, rect);
    return (rect);
}

void destroy_anim(sfMusic *animo, sfSprite *sback, sfSprite *gif)
{
    sfMusic_destroy(animo);
    sfSprite_destroy(sback);
    sfSprite_destroy(gif);
}

void anim_loop(game_t *game, sfIntRect rect,
sfTexture *anim, sfTexture *backg)
{
    int i = 0;
    sfMusic *animo;
    sfTime time = sfSeconds(0.045);
    sfSprite *sback = sfSprite_create();
    sfSprite *gif = sfSprite_create();
    sfVector2f pos = {710, 315};

    sfSprite_setTexture(sback, backg, sfTrue);
    sfSprite_setTexture(gif, anim, sfTrue);
    sfSprite_setTextureRect(gif, rect);
    sfSprite_setPosition(gif, pos);
    animo = sfMusic_createFromFile("ressources/sound_anim.ogg");
    while (sfRenderWindow_isOpen(game->window->w)) {
        display_first_anim(game, sback, gif);
        rect = change_rect(rect, gif, i, animo);
        i++;
        if (i == 66)
            break;
        sfSleep(time);
    }
    destroy_anim(animo, sback, gif);
}

void anim(game_t *game)
{
    sfIntRect rect;
    sfTexture *anim = sfTexture_createFromFile("ressources/f_anim.png", NULL);
    sfTexture *backg = sfTexture_createFromFile("ressources/ac0.png", NULL);

    rect.width = 500;
    rect.height = 450;
    rect.left = 0;
    rect.top = 0;
    anim_loop(game, rect, anim, backg);
    sfTexture_destroy(anim);
    sfTexture_destroy(backg);
}