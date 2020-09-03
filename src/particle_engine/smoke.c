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

void render_smoke(effect_t *effect, sfRenderWindow *window)
{
    for (int i = 0; i < effect->density; i++) {
        if (effect->particles[i].z > 0)
            sfRenderWindow_drawRectangleShape(window,
            effect->particles[i].rect, NULL);
    }
}

void update_smoke(effect_t *effect, int i)
{
    if (effect->particles[i].z <= 0 ||
    effect->particles[i].pos.y > effect->pos.y + effect->size.y ||
    effect->particles[i].pos.x > effect->pos.x + effect->size.x ||
    effect->particles[i].pos.x < effect->pos.y - effect->size.x) {
        effect->particles[i].z = -1;
        if (effect->loop == 1) {
            effect->particles[i] = random_smoke_particle(effect,
            effect->particles[i]);
        }
    } else {
        effect->particles[i].pos.y += effect->particles[i].dir.y;
        effect->particles[i].pos.x += effect->particles[i].dir.x;
        effect->particles[i].dir.x += effect->particles[i].speed.x;
        effect->particles[i].dir.y += effect->particles[i].speed.y;
        sfRectangleShape_setPosition(effect->particles[i].rect,
            effect->particles[i].pos);
        effect->particles[i].z--;
    }
}

void smoke(effect_t *effect, sfRenderWindow *window)
{
    for (int i = 0; i < effect->density; i++) {
        update_smoke(effect, i);
    }
    render_smoke(effect, window);
}

particle_t random_smoke_particle(effect_t *effect, particle_t particle)
{
    int red;
    int green;

    particle.pos.x = effect->pos.x + (effect->size.x / 2);
    particle.pos.y = effect->pos.y + (effect->size.y / 2);
    particle.z = (rand() % 100) + 100;
    particle.size = (sfVector2f) {rand() % 10 + 10, 10};
    particle.dir = (sfVector2f) {rand() % 5 + 0.5, rand() % 10 * -1};
    if (rand() % 2)
        particle.dir.x *= -1;
    particle.speed.y = (rand() % 100) / 100 + 1;
    particle.speed.x = effect->wind;
    red = rand() % (abs(effect->color_range[0].r -
    effect->color_range[1].r) + 1) + effect->color_range[1].r;
    green = rand() % (abs(effect->color_range[0].g -
    effect->color_range[1].g) + 1) + effect->color_range[1].g;
    particle.color = sfColor_fromRGBA(red, green, rand() % 50, rand() % 255);
    return (particle);
}