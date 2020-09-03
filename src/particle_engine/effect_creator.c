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

particle_t *create_rain_particles(effect_t *effect)
{
    particle_t *particles = my_malloc(sizeof(particle_t) * effect->density);

    for (int i = 0; i < effect->density; i++) {
        particles[i] = random_rain_particle(effect, particles[i]);
        particles[i].rect = make_rectangle(particles[i].pos, particles[i].size,
            particles[i].color);
    }
    return (particles);
}

effect_t *create_rain(void)
{
    effect_t *effect = my_malloc(sizeof(effect_t));

    effect->pos = (sfVector2i) {0, 0};
    effect->size = (sfVector2i) {1920, 1080};
    effect->type = 0;
    effect->loop = 1;
    effect->color_range = my_malloc(sizeof(sfColor) * 2);
    effect->color_range[0] = (sfColor) {0, 0, 255};
    effect->color_range[1] = (sfColor) {0, 0, 120};
    effect->shape = 0;
    effect->density = 200;
    effect->wind = -1;
    effect->particles = create_rain_particles(effect);
    return (effect);
}

particle_t *create_smoke_particles(effect_t *effect)
{
    particle_t *particles = my_malloc(sizeof(particle_t) * effect->density);

    for (int i = 0; i < effect->density; i++) {
        particles[i] = random_smoke_particle(effect, particles[i]);
        particles[i].rect = make_rectangle(particles[i].pos, particles[i].size,
            particles[i].color);
    }
    return (particles);
}

effect_t *create_smoke(void)
{
    effect_t *effect = my_malloc(sizeof(effect_t));

    effect->pos = (sfVector2i) {280, 50};
    effect->size = (sfVector2i) {5, 10};
    effect->type = 1;
    effect->loop = 1;
    effect->color_range = my_malloc(sizeof(sfColor) * 2);
    effect->color_range[0] = (sfColor) {255, 120, 0};
    effect->color_range[1] = (sfColor) {0, 0, 0};
    effect->shape = 0;
    effect->density = 10;
    effect->wind = 0;
    effect->particles = create_smoke_particles(effect);
    return (effect);
}