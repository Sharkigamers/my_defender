/*
** EPITECH PROJECT, 2019
** defender
** File description:
** Our defednder : Kevin / Gabriel
*/

#include "my.h"

int defender(void)
{
    dwd_t dwd;
    mob_t mob;
    to_t to;

    ini_all(&dwd, &mob, &to);
    while (sfRenderWindow_isOpen(dwd.window)) {
        show_menu(&dwd, &to, &mob);
        main_game(&dwd, &mob, &to);
        sfRenderWindow_display(dwd.window);
    }
    destroy_all(&dwd, &mob, &to);
    return (0);
}
