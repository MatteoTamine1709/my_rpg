/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_init
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <SFML/Audio/Music.h>
#include "functions.h"

game_t *init_window_two(game_t *g)
{
    g->window->t_load = sfTexture_createFromFile("ressources/bg.png", NULL);
    g->window->t_fight = sfTexture_createFromFile("ressources/bg.png", NULL);
    g->window->t_bt = sfTexture_createFromFile("ressources/bg_bt.png", NULL);
    g->window->t_go = sfTexture_createFromFile("ressources/game_over.png",
    NULL);
    g->window->t_tbc = sfTexture_createFromFile("ressources/tbc.png", NULL);
    g->window->backg = sfSprite_create();
    return (g);
}

window_t *init_window(game_t *g)
{
    g->window = my_malloc(sizeof(window_t));
    g->window->mode = (sfVideoMode) {1920, 1080, 32};
    g->window->w = sfRenderWindow_create(g->window->mode, "RPG",
    sfFullscreen | sfResize | sfClose, NULL);
    sfRenderWindow_setMouseCursor(g->window->w,
    sfCursor_createFromSystem(sfCursorCross));
    sfRenderWindow_setFramerateLimit(g->window->w, 60);
    anim(g);
    g->window->t_menu = sfTexture_createFromFile("ressources/bg2.png", NULL);
    g->window->t_settings =
    sfTexture_createFromFile("ressources/bg_settings.jpg", NULL);
    g->window->t_help = sfTexture_createFromFile("ressources/bg_help.jpg",
    NULL);
    g = init_window_two(g);
    return (g->window);
}

game_t *create_game_load(game_t *game)
{
    game->items = load_items("saves/save1/items", game);
    game->weapons = load_weapons("saves/save1/weapons", game);
    game->current_map = load_current_map("saves/save1/current_map_load");
    game->bg_map = create_map(my_strcat("saves/save1/background/",
    game->current_map));
    game->mg_map = create_map(my_strcat("saves/save1/middleground/",
    game->current_map));
    game->fg_map = create_map(my_strcat("saves/save1/foreground/",
    game->current_map));
    game->npcs = load_npc(my_strcat("saves/save1/npc/", game->current_map),
    game);
    game->props = load_props(my_strcat("saves/save1/props/",
    game->current_map), game);
    game->lights = load_light(my_strcat("saves/save1/light/",
    game->current_map), game);
    game->effect_index = load_effect(my_strcat("saves/save1/effect/",
    game->current_map), game);
    game->redirects = load_redirect(my_strcat("saves/save1/redirection/",
    game->current_map), game);
    game->unselected_case_inv = 0;
    game->unselected_case_inv = 0;
    return (game);
}

void create_game_2(game_t *game)
{
    game = create_game_load(game);
    game->player = load_player("saves/save1/player", game);
    game->map_images = create_images(game);
    game->clock = sfClock_create();
    game->fps_clock = sfClock_create();
    game->frame = 0;
    game->nb_effect_max = 2;
    game->battle = my_malloc(sizeof(battle_t));
    game->high_or_low = 1;
    game->music = init_music(game);
    game->unselected_case_inv = 0;
    game->selected_case_inv = 0;
}

game_t *create_game(void)
{
    game_t *game = my_malloc(sizeof(game_t));

    srand(time(NULL));
    game->window = init_window(game);
    create_game_2(game);
    game->effects = my_malloc(sizeof(effect_t) * game->nb_effect_max);
    game->effects[0] = create_rain();
    game->effects[1] = create_smoke();
    game->buttons = init_buttons();
    game->manage_index = 0;
    game = quest_one(game);
    game = quest_two(game);
    game = quest_three(game);
    game = quest_four(game);
    game->talk_sprite = sfSprite_create();
    game->talk_text = sfTexture_createFromFile("ressources/speech.jpg", NULL);
    sfSprite_setTexture(game->talk_sprite, game->talk_text, sfTrue);
    sfSprite_setTextureRect(game->talk_sprite, (sfIntRect) {0, 0, 200, 100});
    return (game);
}