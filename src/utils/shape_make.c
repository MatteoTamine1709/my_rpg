/*
** EPITECH PROJECT, 2020
** MUL_my_radar_2019
** File description:
** shape_make
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stddef.h>
#include "my.h"

sfCircleShape *make_circle(sfVector2f position, float radius, sfColor color)
{
    sfCircleShape *shape;

    shape = sfCircleShape_create();
    sfCircleShape_setRadius(shape, radius);
    sfCircleShape_setPosition(shape, position);
    sfCircleShape_setFillColor(shape, color);
    sfCircleShape_rotate(shape, 0);
    sfCircleShape_setOutlineColor(shape, sfTransparent);
    sfCircleShape_setOutlineThickness(shape, 1.00);
    return (shape);
}

sfRectangleShape *make_square(sfVector2f position)
{
    sfRectangleShape *shape;
    sfVector2f scale = {20, 20};

    shape = sfRectangleShape_create();
    sfRectangleShape_setSize(shape, scale);
    sfRectangleShape_setPosition(shape, position);
    sfRectangleShape_setFillColor(shape, sfTransparent);
    sfRectangleShape_setOutlineColor(shape, sfTransparent);
    sfRectangleShape_setOutlineThickness(shape, 1.00);
    return (shape);
}

sfRectangleShape *make_rectangle(sfVector2f position,
    sfVector2f scale, sfColor color)
{
    sfRectangleShape *shape;

    shape = sfRectangleShape_create();
    sfRectangleShape_setSize(shape, scale);
    sfRectangleShape_setPosition(shape, position);
    sfRectangleShape_setFillColor(shape, color);
    sfRectangleShape_setOutlineColor(shape, sfTransparent);
    sfRectangleShape_setOutlineThickness(shape, 1.00);
    return (shape);
}

int is_intersecting_circles(sfCircleShape *c1, sfCircleShape *c2)
{
    sfVector2f position = sfCircleShape_getPosition(c1);
    sfVector2f position2 = sfCircleShape_getPosition(c2);
    int cr = 50;
    int dr = 50;
    float c1x = position.x;
    float c1y = position.y;
    float c2x = position2.x;
    float c2y = position2.y;
    int yes = (c1x - c2x) * (c1x - c2x);
    int nop = (c1y - c2y) * (c1y - c2y);

    if (yes + nop <= ((cr + dr) * (cr + dr)))
        return (1);
    return (0);
}