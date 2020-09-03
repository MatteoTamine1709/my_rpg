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

light_t *load_light_info(char *buff, int size, light_t *lights, int nb_light)
{
    int c_light = 0;
    int index = 0;
    light_t (*set_light_var[])(light_t, int, char *) = {light_pos_x,
        light_pos_y, light_radius, light_color_red, light_color_green,
        light_color_blue, light_color_alpha, light_intensity_a,
        light_intensity_b, light_nb_frame};

    for (int i = get_size_n(buff, 0) + 1; i < size;
        i += (get_size_n(buff, i) + 1)) {
        if (index < 10)
            lights[c_light] = (*set_light_var[index])(lights[c_light], i,
            buff);
        index++;
        if (next_info(buff[i], (int *[3]) {&c_light, &nb_light, &index}) == 1)
            return (lights);
    }
    return (lights);
}

light_t fill_light(void)
{
    light_t light;

    light.pos = (sfVector2f) {-1, -1};
    light.radius = -1;
    light.color = (sfColor) {0, 0, 0, 0};
    light.shapes = NULL;
    light.intensity_a = -1;
    light.intensity_b = -1;
    light.frame = 0;
    return (light);
}

light_t *set_light_design(light_t *lights, int nb_light)
{
    int max = 0;
    sfVector2f pos;
    int radius = 0;

    for (int i = 0; i < nb_light; i++) {
        max = lights[i].intensity_a > lights[i].intensity_b ?
        lights[i].intensity_a : lights[i].intensity_b;
        radius = 0;
        pos.x = lights[i].pos.x + lights[i].radius;
        pos.y = lights[i].pos.y + lights[i].radius;
        lights[i].shapes = my_malloc(sizeof(sfCircleShape *) * max);
        for (int j = 0; j < max; j++) {
            lights[i].shapes[j] = make_circle(pos, radius, lights[i].color);
            pos.x -= (lights[i].radius / max);
            pos.y -= (lights[i].radius / max);
            radius += (lights[i].radius / max);
        }
    }
    return (lights);
}

light_t *load_light(char *filepath, game_t *game)
{
    int fd = open(filepath, O_RDONLY);
    char buff[2000];
    int size = 0;
    light_t *lights;
    game->nb_light = 0;

    if (fd == -1)
        return NULL;
    size = read(fd, buff, sizeof(char) * 2000);
    if (size < 2)
        return (NULL);
    buff[size] = '\0';
    game->nb_light = my_atoi_n(buff, 0);
    lights = my_malloc(sizeof(light_t) * game->nb_light);
    for (int i = 0; i < game->nb_light; i++)
        lights[i] = fill_light();
    lights = load_light_info(buff, size, lights, game->nb_light);
    lights = set_light_design(lights, game->nb_light);
    return (lights);
}