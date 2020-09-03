/*
** EPITECH PROJECT, 2020
** MUL_my_radar_2019
** File description:
** game
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef PARTICLE_H_
#define PARTICLE_H_

typedef struct particle_t
{
    sfVector2f pos;
    sfVector2f size;
    sfVector2f dir;
    sfVector2f speed;
    float z;
    sfColor color;
    sfRectangleShape *rect;
}particle_t;

typedef struct effect_s
{
    sfVector2i pos;
    sfVector2i size;
    int type;
    int loop;
    int shape;
    int density;
    float wind;
    sfColor *color_range;
    particle_t *particles;
} effect_t;

void do_effect(effect_t *effect, sfRenderWindow *window);

effect_t *create_rain(void);
void rain(effect_t *effect, sfRenderWindow *window);
particle_t random_rain_particle(effect_t *effect, particle_t particle);
particle_t *create_rain_particles(effect_t *effect);


effect_t *create_smoke(void);
particle_t *create_smoke_particles(effect_t *effect);
void smoke(effect_t *effect, sfRenderWindow *window);
particle_t random_smoke_particle(effect_t *effect, particle_t particle);

#endif