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
#include <time.h>
#include <SFML/Audio/Music.h>
#include "functions.h"

void quit(game_t *game)
{
    save(game);
    sfRenderWindow_close(game->window->w);
}

game_t *init_window_scene(game_t *g)
{
    g->scenes = malloc(sizeof(scenes_t) * 9);
    g->scenes[0] = menu;
    g->scenes[1] = load;
    g->scenes[2] = settings;
    g->scenes[3] = help;
    g->scenes[4] = game;
    g->scenes[5] = breakt;
    g->scenes[6] = quit;
    g->scenes[7] = game_over;
    g->scenes[8] = tbc;
    return (g);
}

void display_window(game_t *g)
{
    sfEvent event;
    sfTime time;

    g = init_window_scene(g);
    while (sfRenderWindow_isOpen(g->window->w)) {
        sfRenderWindow_clear(g->window->w, sfColor_fromRGB(30, 30, 30));
        (*g->scenes[g->manage_index])(g);
        event_manager(g);
        sfRenderWindow_display(g->window->w);
    }
    sfMusic_destroy(g->music->menu);
    sfMusic_destroy(g->music->game);
}

int main(int ac, char **av)
{
    ERR_MALLOC = 0;
    FREE_LIST = malloc(sizeof(free_list_t *));
    (*FREE_LIST) = malloc(sizeof(free_list_t));
    (*FREE_LIST)->p = NULL;
    (*FREE_LIST)->next = NULL;
    game_t *game = create_game();
    if (ERR_MALLOC == 1)
        return (84);
    create_animations(game);
    if (ERR_MALLOC == 1)
        return (84);
    display_window(game);
    if (ERR_MALLOC == 0) {
        free_all_list();
        return (0);
    }
    return (84);
}