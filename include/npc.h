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
#include "quest.h"
#include "item.h"

#ifndef NPC_H_
#define NPC_H_

typedef struct stat_s
{
    int level;
    int hp;
    int max_hp;
    int weapon_index;
    int chest_index;
    int leg_index;
    weapon_t weapon;
    item_t chest;
    item_t leg;
    item_t *conso;
    int speed;
    int dodge;
    int crit;
    int stamina;
    int max_stamina;
    int regen_stamina;
    int dodge_accurancy;
} stat_t;

typedef struct npc_s
{
    sfVector2f pos;
    sfVector2f hitbox_size;
    int type;
    int frame_count;

    char *sound_path;
    char *texture_path;
    char *texture_path_fight;
    char **animation;
    int text;
    sfVector2f *movements;
    sfVector2f destination;
    sfVector2f start;
    int move_index;
    int side;
    int nb_movements;
    int walk_speed;
    stat_t *stat;
    int nb_items;
    int *items;
    int nb_weapons;
    int *weapons;

    int anim;
    int text_cursor;
    int start_dialog;

    int frame;
    sfSound *sound;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    int render_state;

    int quest;
} npc_t;

#endif