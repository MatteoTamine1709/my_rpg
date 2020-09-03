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
#include "particle.h"

#ifndef ITEM_H_
#define ITEM_H_

typedef struct weapon_s
{
    sfSprite *sprite;
    sfTexture **texture_fight;
    char **texture_path_fight;
    sfTexture *texture;
    char *texture_path;
    int *cds;
    int *nb_frame_dodges;
    int *nb_frame_anim;
    sfIntRect *anim_rects;
    int price;
    char *name;
    int level_power;
    int stamina;
    int crit;
    int damage;
    int nb_shot;
    int malus_hp;
    int malus_speed;
    int malus_stamina;
    int malus_agility;
    int malus_crit;
    int malus_stun;
}weapon_t;

typedef struct item_s
{
    sfSprite *sprite;
    sfTexture *texture;
    char *texture_path;
    int price;
    int type;
    int hp;
    int speed;
    int stamina;
    int dodge;
    int crit;
    char *name;
    int level_power;
}item_t;

#endif