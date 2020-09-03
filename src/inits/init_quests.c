/*
** EPITECH PROJECT, 2024
** MUL_my_rpg_2019
** File description:
** MUL_my_rpg_2019
*/

#include "game.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <SFML/Audio/Music.h>
#include "functions.h"

game_t *quest_one(game_t *game)
{
    game->nb_quest = 4;
    game->quests = malloc(sizeof(quest_t) * 5);
    game->player->numberquests = 0;
    game->player->has_quest = 1;
    game->quests[0].type = 1;
    game->quests[0].status = 0;
    game->quests[0].map_npc_receiver = "map3";
    game->quests[0].index_npc_receiver = 2;
    game->quests[0].map_npc_talk = "";
    game->quests[0].index_npc_talk = -1;
    game->player->quest = game->quests[0];
    return (game);
}

game_t *quest_two(game_t *game)
{
    game->quests[1].type = 1;
    game->quests[1].status = 0;
    game->quests[1].map_npc_receiver = "map1";
    game->quests[1].index_npc_receiver = 1;
    game->quests[1].map_npc_talk = "map3";
    game->quests[1].index_npc_talk = 2;
    return (game);
}

game_t *quest_three(game_t *game)
{
    game->quests[2].type = 1;
    game->quests[2].status = 0;
    game->quests[2].map_npc_receiver = "map1";
    game->quests[2].index_npc_receiver = 8;
    game->quests[2].map_npc_talk = "map1";
    game->quests[2].index_npc_talk = 1;
    return (game);
}

game_t *quest_four(game_t *game)
{
    game->quests[3].type = 1;
    game->quests[3].status = 0;
    game->quests[3].map_npc_receiver = "map4";
    game->quests[3].index_npc_receiver = 7;
    game->quests[3].map_npc_talk = "map1";
    game->quests[3].index_npc_talk = 8;
    return (game);
}