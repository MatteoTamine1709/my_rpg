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
#include "npc.h"

#ifndef GAME_H_
#define GAME_H_

typedef struct window_s
{
    sfVideoMode mode;
    sfRenderWindow *w;
    sfTexture *t_menu;
    sfTexture *t_settings;
    sfTexture *t_help;
    sfTexture *t_load;
    sfTexture *t_fight;
    sfTexture *t_bt;
    sfTexture *t_go;
    sfTexture *t_tbc;
    sfSprite *backg;
}window_t;

typedef struct image_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    char *redirection;
    sfVector2i size;
    sfImage *hitbox;
} image_t;

typedef struct redirect_s
{
    sfVector2f pos;
    sfVector2f hitbox_size;
    char *redirect_name;
    sfVector2f dest_pos;
    sfVector2f dest_size;
}redirect_t;

typedef struct light_s
{
    sfVector2f pos;
    sfColor color;
    int radius;
    sfCircleShape **shapes;
    int intensity_a;
    int intensity_b;
    int nb_frame_switch;
    int frame;
}light_t;

typedef struct map_s
{
    char *top;
    char *right;
    char *bot;
    char *left;
    int **map;
    int nb_effect;
    effect_t **effects;
}map_t;

typedef struct prop_s
{
    sfVector2f pos;
    sfVector2f hitbox_size;
    char *texture_path;
    sfTexture *texture;
    sfSprite *sprite;
}prop_t;

typedef struct inventory_s
{
    sfSprite *bg_sprite;
    sfTexture *bg_texture;
    sfSprite *sprite;
    sfTexture *texture;
    item_t *items;
    weapon_t *weapons;
    int *item_num;
    int *weapon_num;
    int is_full;
}inventory_t;

typedef struct player_s
{
    int stuck;
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *texture_fight;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f destination_point;
    sfVector2f dir;
    int anim;
    int frame;
    float walk_speed;
    stat_t *stat;
    inventory_t *inventory;
    int npc_interact_index;
    sfSprite *shop_sprite;
    sfTexture *shop_texture;
    int inventory_open;
    int in_shop;
    int in_fight;
    int has_quest;
    int numberquests;
    quest_t quest;
}player_t;

typedef struct battle_s
{
    npc_t *npc;
    player_t *player;
    int dodge;
    int player_speed;
    int npc_speed;
    int side;
    int attack_type;
    int start;
    int slow_mo;
    int shot;
    int frame;
    int reaction;
    int *player_cds;
    int *npc_cds;
    sfRectangleShape *total_time;
    sfRectangleShape *current_time;
    sfRectangleShape **player_cds_rect;
    sfSprite *sprite_effect;
    sfSprite *sprite_incantation;
    int too_early;
}battle_t;

typedef struct button_s
{
    sfVector2f pos;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
}button_t;

typedef struct music_s
{
    sfMusic *menu;
    sfMusic *game;
}music_t;

typedef struct f_game
{
    int w_music;
    int high_or_low;
    music_t *music;
    window_t *window;
    int nb_map_image;
    image_t **map_images;
    map_t *bg_map;
    map_t *mg_map;
    map_t *fg_map;
    int nb_npc;
    npc_t *npcs;
    int nb_props;
    prop_t *props;
    int nb_light;
    light_t *lights;
    int nb_redirect;
    redirect_t *redirects;
    int nb_item;
    int nb_weapon;
    item_t *items;
    weapon_t *weapons;
    battle_t *battle;
    int frame;
    sfClock *clock;
    sfClock *fps_clock;
    int nb_effect;
    int nb_effect_max;
    int selected_case_inv;
    int unselected_case_inv;
    int *effect_index;
    effect_t **effects;
    char *current_map;
    button_t **buttons;
    int manage_index;
    void (**scenes)(struct f_game *);
    void (**b_anim)(struct f_game *, button_t *, int i, int x);

    player_t *player;
    int nb_quest;
    quest_t *quests;

    sfSprite *talk_sprite;
    sfTexture *talk_text;
}game_t;

typedef void (*b_anim_t)(game_t *, button_t *, int i, int x);
typedef void (*scenes_t)(game_t *);
typedef weapon_t (*weapon_array)(weapon_t, int, char *);

typedef struct free_list_s
{
    void *p;
    struct free_list_s *next;
} free_list_t;

free_list_t **FREE_LIST;
int ERR_MALLOC;

#endif
