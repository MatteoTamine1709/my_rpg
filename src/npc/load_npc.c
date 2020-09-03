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

npc_t fill_npc2(npc_t npc)
{
    npc.stat = NULL;
    npc.items = NULL;
    npc.weapons = NULL;
    npc.frame = 0;
    npc.start_dialog = 0;
    npc.text_cursor = 0;
    npc.anim = 0;
    npc.start = (sfVector2f) {-1, -1};
    npc.side = 0;
    npc.move_index = 0;
    npc.render_state = 1;
    return (npc);
}

npc_t fill_npc(void)
{
    npc_t npc;

    npc.pos = (sfVector2f) {-1, -1};
    npc.hitbox_size = (sfVector2f) {-1, -1};
    npc.type = -1;
    npc.sound = NULL;
    npc.texture = NULL;
    npc.sprite = NULL;
    npc.text = 0;
    npc.movements = NULL;
    npc.nb_movements = 0;
    npc.walk_speed = 0;
    npc.destination = (sfVector2f) {-1, -1};
    npc = fill_npc2(npc);
    return (npc);
}

npc_t set_npc_stuff(npc_t npc, game_t *game)
{
    if (npc.stat != NULL) {
        npc.stat->weapon = game->weapons[npc.stat->weapon_index];
        npc.stat->chest = game->items[npc.stat->weapon_index];
        npc.stat->leg = game->items[npc.stat->weapon_index];
        npc.stat->conso = NULL;
    }
    return (npc);
}

npc_t *set_npc_design(npc_t *npcs, int nb_npc, game_t *game)
{
    for (int i = 0; i < nb_npc; i++) {
        npcs[i].sprite = sfSprite_create();
        npcs[i].rect = (sfIntRect) {0, 0, 60, 60};
        npcs[i].texture =
        sfTexture_createFromFile(npcs[i].texture_path, NULL);
        sfSprite_setTexture(npcs[i].sprite, npcs[i].texture, sfFalse);
        sfSprite_setTextureRect(npcs[i].sprite, npcs[i].rect);
        sfSprite_setPosition(npcs[i].sprite, npcs[i].pos);
        npcs[i].start = npcs[i].pos;
        npcs[i] = set_npc_stuff(npcs[i], game);
        if (npcs[i].movements != NULL)
            npcs[i].destination = npcs[i].movements[0];
    }
    return (npcs);
}

npc_t *load_npc(char *filepath, game_t *game)
{
    int fd = open(filepath, O_RDONLY);
    char buff[2000];
    int size = 0;
    npc_t *npcs;
    game->nb_npc = 0;

    if (fd == -1)
        return NULL;
    size = read(fd, buff, sizeof(char) * 2000);
    if (size < 2)
        return (NULL);
    buff[size] = '\0';
    game->nb_npc = my_atoi_n(buff, 0);
    npcs = my_malloc(sizeof(npc_t) * game->nb_npc);
    for (int i = 0; i < game->nb_npc; i++)
        npcs[i] = fill_npc();
    npcs = load_npc_info(buff, size, npcs, game->nb_npc);
    npcs = set_npc_design(npcs, game->nb_npc, game);
    return (npcs);
}