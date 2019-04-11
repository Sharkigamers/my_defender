/*
** EPITECH PROJECT, 2019
** defender
** File description:
** cond_menu
*/

#include "my.h"

void cond_menu(dwd_t *dwd, to_t *to)
{
    cond_play(dwd);
    cond_shop(dwd);
    cond_story(dwd);
    cond_leave(dwd);
    cond_option(dwd);
    show_menu_play(dwd, to);
    show_shop(dwd);
    show_story(dwd);
    show_option(dwd);
}

void anime_menu(dwd_t *dwd)
{
    static sfIntRect rect = {0, 0, 1190, 1190};

    dwd->time = sfClock_getElapsedTime(dwd->clock);
    dwd->sec = dwd->time.microseconds / 1000000.0;
    if (dwd->sec > 0.11) {
        rect.left = rect.left + 1200;
        sfSprite_setTextureRect(dwd->menu_s, rect);
        if (rect.left >= 8400)
            rect.left = 0;
        sfClock_restart(dwd->clock);
    }
}
