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
#include <math.h>
#include "functions.h"
#include "my.h"

weapon_t copy_weapon_two(weapon_t weapon, weapon_t src)
{
    weapon.nb_shot = src.nb_shot;
    weapon.stamina = src.stamina;
    weapon.malus_speed = src.malus_speed;
    weapon.malus_stamina = src.malus_stamina;
    weapon.malus_agility = src.malus_agility;
    weapon.malus_crit = src.malus_crit;
    weapon.malus_stun = src.malus_stun;
    weapon.sprite = sfSprite_create();
    weapon.texture = sfTexture_createFromFile(weapon.texture_path, NULL);
    weapon.texture_fight = src.texture_fight;
    weapon.nb_frame_anim = src.nb_frame_anim;
    weapon.anim_rects = src.anim_rects;
    sfSprite_setTexture(weapon.sprite, weapon.texture, sfFalse);
    return (weapon);
}

weapon_t copy_weapon(weapon_t src)
{
    weapon_t weapon;

    weapon.name = src.name;
    weapon.price = src.price;
    weapon.texture_path = src.texture_path;
    weapon.texture_path_fight = src.texture_path_fight;
    weapon.damage = src.damage;
    weapon.level_power = src.level_power;
    weapon.crit = src.crit;
    weapon.cds = src.cds;
    weapon.nb_frame_dodges = my_malloc(sizeof(int) * 3);
    if (weapon.nb_frame_dodges == NULL)
        return (weapon);
    for (int i = 0; i < 3; i++)
        weapon.nb_frame_dodges[i] = src.nb_frame_dodges[i];
    weapon = copy_weapon_two(weapon, src);
    return (weapon);
}

item_t copy_item(item_t src)
{
    item_t item;

    item.price = src.price;
    item.type = src.type;
    item.hp = src.hp;
    item.speed = src.speed;
    item.stamina = src.stamina;
    item.dodge = src.dodge;
    item.crit = src.crit;
    item.name = src.name;
    item.level_power = src.level_power;
    item.sprite = sfSprite_create();
    item.texture = sfTexture_createFromFile(src.texture_path, NULL);
    sfSprite_setTexture(item.sprite, item.texture, sfFalse);
    return (item);
}