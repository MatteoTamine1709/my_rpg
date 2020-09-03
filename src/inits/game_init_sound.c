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

void sound_click(void)
{
    sfMusic *music = sfMusic_createFromFile("ressources/button_click.ogg");
    sfTime time = sfSeconds(0.1);

    sfMusic_setVolume(music, 10);
    sfMusic_play(music);
    sfSleep(time);
    sfMusic_destroy(music);
}

music_t *init_music(game_t *game)
{
    game->w_music = 2;
    game->music = my_malloc(sizeof(music_t));
    game->music->menu = sfMusic_createFromFile("ressources/menu_music.ogg");
    sfMusic_setVolume(game->music->menu, 10);
    sfMusic_setLoop(game->music->menu, sfTrue);
    game->music->game = sfMusic_createFromFile("ressources/game_music.ogg");
    sfMusic_setVolume(game->music->game, 20);
    sfMusic_setLoop(game->music->game, sfTrue);
    return (game->music);
}