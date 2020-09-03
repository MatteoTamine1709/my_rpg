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
#include "my.h"

void display_lights(light_t *lights, game_t *game)
{
    int max = 0;

    for (int i = 0; i < game->nb_light; i++) {
        lights[i].frame++;
        max = lights[i].intensity_b;
        if (lights[i].frame % (lights[i].nb_frame_switch * 2) <
            lights[i].nb_frame_switch)
            max = lights[i].intensity_a;
        for (int j = 0; j < max; j++)
            sfRenderWindow_drawCircleShape(game->window->w, lights[i].shapes[j],
                NULL);
    }
}