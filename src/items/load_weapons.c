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

weapon_t *load_weapon_info(char *buff, int size, weapon_t *weapons,
    int nb_weapon)
{
    int c_weapon = 0;
    int index = 0;
    weapon_array *set_weapon_var = set_weapon_pointer();
    for (int i = get_size_n(buff, 0) + 1; i < size;
        i += (get_size_n(buff, i) + 1)) {
        if (index < 16)
            weapons[c_weapon] = (*set_weapon_var[index])(weapons[c_weapon], i,
                buff);
        index++;
        if (next_info(buff[i], (int *[3]) {&c_weapon, &nb_weapon, &index}) == 1)
            return (weapons);
    }
    return (weapons);
}

weapon_t fill_weapon(void)
{
    weapon_t weapon;

    weapon.name = NULL;
    weapon.price = -1;
    weapon.texture_path = NULL;
    weapon.texture_path_fight = NULL;
    weapon.damage = -1;
    weapon.level_power = -1;
    weapon.crit = -1;
    weapon.cds = NULL;
    weapon.nb_frame_dodges = NULL;
    weapon.nb_frame_anim = NULL;
    weapon.malus_speed = -1;
    weapon.malus_stamina = -1;
    weapon.malus_agility = -1;
    weapon.malus_crit = -1;
    weapon.malus_stun = -1;
    return (weapon);
}

weapon_t *set_weapon_texture_fight(weapon_t *weapons, int i)
{
    sfVector2u size;

    weapons[i].anim_rects = my_malloc(sizeof(sfIntRect) * 4);
    weapons[i].texture_fight = my_malloc(sizeof(sfTexture *) * 4);
    for (int j = 0; j < 4; j++) {
        weapons[i].texture_fight[j] = sfTexture_createFromFile(
        weapons[i].texture_path_fight[j], NULL);
        size = sfTexture_getSize(weapons[i].texture_fight[j]);
        weapons[i].anim_rects[j] = (sfIntRect)
        {0, 0, size.x / weapons[i].nb_frame_anim[j], size.y};
    }
    return (weapons);
}

weapon_t *set_weapon_design(weapon_t *weapons, int nb_weapon)
{
    for (int i = 0; i < nb_weapon; i++) {
        weapons[i].sprite = sfSprite_create();
        weapons[i].texture = sfTexture_createFromFile(weapons[i].texture_path,
            NULL);
        sfSprite_setTexture(weapons[i].sprite, weapons[i].texture, sfFalse);
        if (weapons[i].texture_path_fight != NULL)
            weapons = set_weapon_texture_fight(weapons, i);
    }
    return (weapons);
}

weapon_t *load_weapons(char *filepath, game_t *game)
{
    int fd = open(filepath, O_RDONLY);
    char buff[2000];
    int size;
    int nb_weapon = 0;
    weapon_t *weapons = NULL;
    game->nb_weapon = 0;

    if (fd == -1)
        return NULL;
    size = read(fd, buff, sizeof(char) * 2000);
    buff[size] = '\0';
    nb_weapon = my_atoi_n(buff, 0);
    weapons = my_malloc(sizeof(weapon_t) * nb_weapon);
    for (int i = 0; i < nb_weapon; i++)
        weapons[i] = fill_weapon();
    weapons = load_weapon_info(buff, size, weapons, nb_weapon);
    weapons = set_weapon_design(weapons, nb_weapon);
    game->nb_weapon = nb_weapon;
    return (weapons);
}