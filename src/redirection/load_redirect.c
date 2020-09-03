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

redirect_t *load_redirect_info(char *buff, int size, redirect_t *redirects,
    int nb_redirect)
{
    int c_redirect = 0;
    int index = 0;
    redirect_t (*set_redirect_var[])(redirect_t, int, char *) = {redirec_pos_x,
        redirect_pos_y, redirect_hitbox_x, redirect_hitbox_y, redirect_name,
        redirect_dest_pos_x, redirect_dest_pos_y, redirect_dest_size_x,
        redirect_dest_size_y};
    for (int i = get_size_n(buff, 0) + 1; i < size;
        i += (get_size_n(buff, i) + 1)) {
        if (index < 9)
            redirects[c_redirect] = (*set_redirect_var[index])
            (redirects[c_redirect], i, buff);
        index++;
        if (next_info(buff[i], (int *[3]) {&c_redirect, &nb_redirect, &index})
            == 1)
            return (redirects);
    }
    return (redirects);
}

redirect_t fill_redirect(void)
{
    redirect_t redirect;

    redirect.pos = (sfVector2f) {-1, -1};
    redirect.hitbox_size = (sfVector2f) {-1, -1};
    redirect.redirect_name = NULL;
    redirect.dest_pos = (sfVector2f) {-1, -1};
    return (redirect);
}

redirect_t *load_redirect(char *filepath, game_t *game)
{
    int fd = open(filepath, O_RDONLY);
    char buff[2000];
    int size;
    int nb_redirect = 0;
    redirect_t *redirects;
    game->nb_redirect = 0;

    if (fd == -1)
        return NULL;
    size = read(fd, buff, sizeof(char) * 2000);
    if (size < 2)
        return (NULL);
    buff[size] = '\0';
    nb_redirect = my_atoi_n(buff, 0);
    redirects = my_malloc(sizeof(redirect_t) * nb_redirect);
    for (int i = 0; i < nb_redirect; i++)
        redirects[i] = fill_redirect();
    redirects = load_redirect_info(buff, size, redirects, nb_redirect);
    game->nb_redirect = nb_redirect;
    return (redirects);
}