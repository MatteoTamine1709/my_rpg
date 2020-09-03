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
#include "particle.h"
#include <stdlib.h>

void rain(effect_t *effect, sfRenderWindow *window)
{
    for (int i = 0; i < effect->density; i++) {
        if (effect->loop == 1 &&
            effect->particles[i].pos.y >= effect->size.y + effect->pos.y)
            effect->particles[i] = random_rain_particle(effect,
            effect->particles[i]);
        if (effect->particles[i].pos.y < effect->size.y + effect->pos.y) {
            effect->particles[i].pos.y += effect->particles[i].speed.y;
            effect->particles[i].pos.x += effect->particles[i].speed.x;
            sfRectangleShape_setPosition(effect->particles[i].rect,
            effect->particles[i].pos);
        }
    }
    for (int i = 0; i < effect->density; i++) {
        if (effect->particles[i].pos.y < effect->size.y + effect->pos.y)
            sfRenderWindow_drawRectangleShape(window,
            effect->particles[i].rect, NULL);
    }
}

particle_t random_rain_particle(effect_t *effect, particle_t particle)
{
    particle.pos.x = rand() % effect->size.x + effect->pos.x;
    particle.pos.y = -10;
    particle.z = rand() % 10000 + 1;
    particle.size = (sfVector2f) {5 * particle.z / 10000 + 1,
        30 * particle.z / 10000 + 1};
    particle.dir = (sfVector2f) {0, 0};
    particle.speed.y = rand() % (int)(20 * (10000.0 / particle.z) + 1) + 5;
    particle.speed.x = effect->wind;
    particle.color = sfColor_fromRGBA(
        rand() % (abs(effect->color_range[0].r - effect->color_range[1].r) + 1)
        + effect->color_range[1].r,
        rand() % (abs(effect->color_range[0].g - effect->color_range[1].g) + 1)
        + effect->color_range[1].g,
        rand() % (abs(effect->color_range[0].b - effect->color_range[1].b) + 1)
        + effect->color_range[1].b,
        rand() % ((int)(particle.z * 255 / 10000) + 1));
    return (particle);
}