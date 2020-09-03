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

#ifndef FUNCTION_H_
#define FUNCTION_H_

sfCircleShape *make_circle(sfVector2f position, float radius, sfColor color);
sfRectangleShape *make_square(sfVector2f position);
sfRectangleShape *make_rectangle(sfVector2f position,
sfVector2f scale, sfColor color);
int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2);
float dist(float x1, float y1, float x2, float y2);
int my_atoi(char *str);
int my_atoi_n(char *str, int index);
int my_atoi_dot(char *str, int index);
char *get_string(char *buff, int index);
char *get_string_dot(char *buff, int index);
int get_size_n(char *buff, int index);
int get_size_dot(char *buff, int index);
char *my_strcat(char *dest, char *src);
char *my_strdup(char *src);

char *get_top(char *buff);
char *get_right(char *buff);
char *get_bot(char *buff);
char *get_left(char *buff);

map_t *create_map(char *map_path);
int get_start(char *);

image_t **create_images(game_t *game);

char *load_current_map(char *filepath);

void displayer(game_t *game);
void display_maps(game_t *game);

sfVector2f get_pos_from_index(int i, inventory_t *inventory);
sfVector2f get_pos_from_index_trying(int i);
sfVector2f get_pos_from_index_trying_scd(int i, sfVector2f pos);
void checking_wich_case_scd(sfVector2i mouse, game_t *game);
void checking_wich_case_thd(sfVector2i mouse, game_t *game);
void checking_wich_case_fst(sfVector2i mouse, game_t *game);
void checking_wich_uncase_fst(sfVector2i mouse, game_t *game);
void checking_wich_uncase_scd(sfVector2i mouse, game_t *game);
void checking_wich_uncase_thd(sfVector2i mouse, game_t *game);
void checking_wich_uncase_fht(sfVector2i mouse, game_t *game);
void switching_items_weapons(game_t *game);
void switching_items_weapons_scd(game_t *game);
void switching_items_weapons_thd(game_t *game);
void switching_items_weapons_fht(game_t *game);
void switching_item_items(game_t *game);
void switching_item_items_scd(game_t *game);
void switching_items_scd(game_t *game, int wich);
void handle_mouse_eventgame(sfVector2i mouse, game_t *game);

map_t *move(char *filepath, game_t *game);
redirect_t *move_redirect(char *filepath, game_t *game);
npc_t *move_npc(char *filepath, game_t *game);
prop_t *move_props(char *filepath, game_t *game);
light_t *move_light(char *filepath, game_t *game);

void free_map(map_t *map);
int **malloc_map(void);

void update_player(player_t *player, game_t *game);
void display_player(player_t *player, sfRenderWindow *window);
game_t *check_map_border(player_t *player, game_t *game);
int hitbox_fg(game_t *game, player_t *player);
int hitbox_mg(game_t *game, player_t *player);
int hitbox_bg(game_t *game, player_t *player);
player_t *load_player(char *filepath, game_t *game);
stat_t *player_stat_level(stat_t *stat, int i);
stat_t *player_stat_hp(stat_t *stat, int i);
stat_t *player_stat_weapon(stat_t *stat, int i);
stat_t *player_stat_chest(stat_t *stat, int i);
stat_t *player_stat_leg(stat_t *stat, int i);
stat_t *player_stat_init(stat_t *stat, int i);
stat_t *player_stat_dodge(stat_t *stat, int i);
stat_t *player_stat_crit(stat_t *stat, int i);
stat_t *player_stat_stamina(stat_t *stat, int i);
stat_t *player_stat_regen(stat_t *stat, int i);
stat_t *player_stat_dodge_acc(stat_t *stat, int i);


int *get_list(char *buff, int *i, int size);

npc_t *load_npc(char *filepath, game_t *game);
npc_t npc_pos_x(npc_t npc, int i, char *buff, int size);
npc_t npc_pos_y(npc_t npc, int i, char *buff, int size);
npc_t npc_hitbox_x(npc_t npc, int i, char *buff, int size);
npc_t npc_hitbox_y(npc_t npc, int i, char *buff, int size);
npc_t npc_type(npc_t npc, int i, char *buff, int size);
npc_t npc_frame_count(npc_t npc, int i, char *buff, int size);
npc_t npc_sound(npc_t npc, int i, char *buff, int size);
npc_t npc_texture(npc_t npc, int i, char *buff, int size);
npc_t npc_texture_fight(npc_t npc, int i, char *buff, int size);
npc_t npc_animation(npc_t npc, int i, char *buff, int size);
npc_t npc_text(npc_t npc, int i, char *buff, int size);
npc_t npc_movements(npc_t npc, int i, char *buff, int size);
npc_t npc_speed(npc_t npc, int i, char *buff, int size);
npc_t npc_stat(npc_t npc, int i, char *buff, int size);
npc_t npc_items(npc_t npc, int i, char *buff, int size);
npc_t npc_weapons(npc_t npc, int i, char *buff, int size);
stat_t *npc_stat_level(stat_t *stat, int i);
stat_t *npc_stat_hp(stat_t *stat, int i);
stat_t *npc_stat_weapon(stat_t *stat, int i);
stat_t *npc_stat_chest(stat_t *stat, int i);
stat_t *npc_stat_leg(stat_t *stat, int i);
stat_t *npc_stat_init(stat_t *stat, int i);
stat_t *npc_stat_dodge(stat_t *stat, int i);
stat_t *npc_stat_crit(stat_t *stat, int i);
stat_t *npc_stat_stamina(stat_t *stat, int i);
stat_t *npc_stat_regen(stat_t *stat, int i);
stat_t *npc_stat_dodge_acc(stat_t *stat, int i);
void display_npc(npc_t *npcs, game_t *game);


prop_t *load_props(char *filepath, game_t *game);
prop_t prop_pos_x(prop_t prop, int i, char *buff);
prop_t prop_pos_y(prop_t prop, int i, char *buff);
prop_t prop_hitbox_x(prop_t prop, int i, char *buff);
prop_t prop_hitbox_y(prop_t prop, int i, char *buff);
prop_t prop_texture(prop_t prop, int i, char *buff);
void display_props(prop_t *props, game_t *game);


item_t *load_items(char *filepath, game_t *game);
item_t item_name(item_t item, int i, char *buff);
item_t item_price(item_t item, int i, char *buff);
item_t item_texture(item_t item, int i, char *buff);
item_t item_type(item_t item, int i, char *buff);
item_t item_level_power(item_t item, int i, char *buff);
item_t item_hp(item_t item, int i, char *buff);
item_t item_speed(item_t item, int i, char *buff);
item_t item_stamina(item_t item, int i, char *buff);
item_t item_agility(item_t item, int i, char *buff);
item_t item_crit(item_t item, int i, char *buff);


weapon_t *load_weapons(char *filepath, game_t *game);
weapon_t weapon_name(weapon_t weapon, int i, char *buff);
weapon_t weapon_price(weapon_t weapon, int i, char *buff);
weapon_t weapon_texture(weapon_t weapon, int i, char *buff);
weapon_t weapon_texture_fight(weapon_t weapon, int i, char *buff);
weapon_t weapon_damage(weapon_t weapon, int i, char *buff);
weapon_t weapon_level_power(weapon_t weapon, int i, char *buff);
weapon_t weapon_crit(weapon_t weapon, int i, char *buff);
weapon_t weapon_nb_shot(weapon_t weapon, int i, char *buff);
weapon_t weapon_stamina(weapon_t weapon, int i, char *buff);
weapon_t weapon_cds(weapon_t weapon, int i, char *buff);
weapon_t weapon_nb_frame_dodges(weapon_t weapon, int i, char *buff);
weapon_t weapon_malus_speed(weapon_t weapon, int i, char *buff);
weapon_t weapon_malus_stamina(weapon_t weapon, int i, char *buff);
weapon_t weapon_malus_agility(weapon_t weapon, int i, char *buff);
weapon_t weapon_malus_crit(weapon_t weapon, int i, char *buff);
weapon_t weapon_malus_stun(weapon_t weapon, int i, char *buff);

weapon_t copy_weapon(weapon_t src);
item_t copy_item(item_t src);

light_t *load_light(char *filepath, game_t *game);
light_t light_pos_x(light_t light, int i, char *buff);
light_t light_pos_y(light_t light, int i, char *buff);
light_t light_radius(light_t light, int i, char *buff);
light_t light_color_red(light_t light, int i, char *buff);
light_t light_color_green(light_t light, int i, char *buff);
light_t light_color_blue(light_t light, int i, char *buff);
light_t light_color_alpha(light_t light, int i, char *buff);
light_t light_intensity_a(light_t light, int i, char *buff);
light_t light_intensity_b(light_t light, int i, char *buff);
light_t light_nb_frame(light_t light, int i, char *buff);
void display_lights(light_t *lights, game_t *game);

int *load_effect(char *filepath, game_t *game);
int *move_effect(char *filepath, game_t *game);


int check_redirect(game_t *game, player_t *player);
game_t *redirect(redirect_t redirect, player_t *player, game_t *game);
redirect_t *load_redirect(char *filepath, game_t *game);
redirect_t redirec_pos_x(redirect_t redirect, int i, char *buff);
redirect_t redirect_pos_y(redirect_t redirect, int i, char *buff);
redirect_t redirect_hitbox_x(redirect_t redirect, int i, char *buff);
redirect_t redirect_hitbox_y(redirect_t redirect, int i, char *buff);
redirect_t redirect_name(redirect_t redirect, int i, char *buff);
redirect_t redirect_dest_pos_x(redirect_t redirect, int i, char *buff);
redirect_t redirect_dest_pos_y(redirect_t redirect, int i, char *buff);
redirect_t redirect_dest_size_x(redirect_t redirect, int i, char *buff);
redirect_t redirect_dest_size_y(redirect_t redirect, int i, char *buff);
game_t *redirect_border(player_t *player, game_t *game);


inventory_t *add_item_inventory(inventory_t *inventory,
item_t item, int index);
inventory_t *add_weapon_inventory(inventory_t *inventory,
weapon_t weapon, int index);
inventory_t *add_item_inventory_pos(inventory_t *inventory,
item_t item, int index, int pos_inv);
inventory_t *add_weapon_inventory_pos(inventory_t *inventory,
weapon_t weapon, int index, int pos_inv);

battle_t *reset_battle(battle_t *battle);
int fight(battle_t *battle, game_t *game);
void event_fight(game_t *game, sfEvent event);
void player_shot(battle_t *battle, game_t *game);
battle_t *update_battle(battle_t *battle, game_t *game);
void update_battle_player(battle_t *battle, game_t *game);
void update_battle_npc(battle_t *battle, game_t *game);
battle_t *player_dodge(battle_t *battle, game_t *game);
battle_t *npc_dodge(battle_t *battle, game_t *game);
battle_t *npc_shot(battle_t *battle);

void event_manager(game_t *game);
void e_menu(game_t *game, sfEvent event, sfVector2i pos);
void e_load(game_t *game, sfEvent event, sfVector2i pos);
void e_settings(game_t *game, sfEvent event, sfVector2i pos);
void e_help(game_t *game, sfEvent event, sfVector2i pos);
void e_game(game_t *game, sfEvent event, sfVector2i pos);
void e_breakt(game_t *game, sfEvent event, sfVector2i pos);
void e_quit(game_t *game, sfEvent event, sfVector2i pos);

button_t **init_buttons(void);
void create_animations(game_t *game);

void menu(game_t *game);
void game(game_t *game);
void load(game_t *game);
void settings(game_t *game);
void help(game_t *game);
void breakt(game_t *game);
void game_over(game_t *game);
void tbc(game_t *game);

void save(game_t *game);
void save_npc(game_t *game);

void display_fight_cd(battle_t *battle, game_t *game);
void display_anim(battle_t *battle, game_t *game);
void display_incantation(battle_t *battle, game_t *game);

void remove_player_stat(player_t *player);
void player_dead(battle_t *battle, game_t *game);
void enemy_dead(battle_t *battle, game_t *game);
int check_if_battle_start(battle_t *battle, game_t *game);
int npc_check_shot(battle_t *battle);
void npc_shot_sprite(battle_t *battle);
void npc_shot_anim(battle_t *battle);
battle_t *npc_shot(battle_t *battle);
int can_player_shot(battle_t *battle, game_t *game, float val);
sfColor get_attack(battle_t *battle, game_t *game);
void player_shot_sprite(battle_t *battle, game_t *game, float val);
void player_shot(battle_t *battle, game_t *game);

game_t *quest_one(game_t *game);
game_t *quest_two(game_t *game);
game_t *quest_three(game_t *game);
game_t *quest_four(game_t *game);

weapon_array *set_weapon_pointer(void);
int *move_effect(char *filepath, game_t *game);
redirect_t *move_redirect(char *filepath, game_t *game);
npc_t *move_npc(char *filepath, game_t *game);
prop_t *move_props(char *filepath, game_t *game);
light_t *move_light(char *filepath, game_t *game);

void sound_click(void);

game_t *create_game(void);
void anim(game_t *game);

void *my_malloc(int size);
void add_free_list(void *p);

void print_list(void);
int get_list_size(void);
void free_all_list(void);

sfIntRect get_rect_pos(game_t *game, npc_t *npc);
npc_t *load_npc_info(char *buff, int size, npc_t *npcs, int nb_npc);
stat_t *get_stat(char *buff, int *i);
sfVector2f *get_movements(char *buff, int *i);

void save_itoa(char *rewrite, int val, int *i, int diff);
void save_itoa_dot(char *rewrite, int val, int *i, int diff);
void save_char(char *rewrite, char *val, int *i, int diff);
void save_npc_fix(char *rewrite, game_t *game, int *i, int diff);
void save_npx_fix_2(char *rewrite, game_t *game, int *i, int diff);
void save_npc_stat_two(char *rewrite, game_t *game, int *i, int diff);
void save_npc_stat(char *rewrite, game_t *game, int *i, int diff);
void save_npc_i_w(char *rewrite, game_t *game, int *i, int diff);
void final_npc_write(char *rewrite, game_t *game, int i, int diff);
void end_save_npc(char *rewrite, game_t *game, int *i, int diff);
void save_npc_walk(char *rewrite, game_t *game, int *i, int diff);
void save_npc(game_t *game);
char *copy_all_npcs(game_t *game, char *buff, int *i, int *diff);
game_t *get_quest(game_t *game, int index);
player_t *check_quest(player_t *player, game_t *game, int index);
void npc_enemy(game_t *game, player_t *player, int i);
void npc_shop(game_t *game, player_t *player, int i);
void npc_end_action(game_t *game, player_t *player, int i);
player_t *set_player_design(player_t *player, game_t *game);

battle_t *set_battle(battle_t *battle, player_t *player, npc_t *npc);
sfVector2f scale_pos_inventory(int i, inventory_t *inventory);
sfVector2f get_pos_from_index(int i, inventory_t *inventory);
inventory_t *set_inventory_shop(inventory_t *inventory, int side, game_t *game);
void sound_click(void);
music_t *init_music(game_t *game);

int next_info(char c, int **arr);

#endif