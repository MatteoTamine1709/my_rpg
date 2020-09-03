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
#include "particle.h"
#include <stdlib.h>

void do_effect(effect_t *effect, sfRenderWindow *window)
{
    void (*effects[])(effect_t *, sfRenderWindow *) = {rain, smoke};

    (*effects[effect->type])(effect, window);
}