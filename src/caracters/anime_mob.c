/*
** EPITECH PROJECT, 2019
** anime_mob.c
** File description:
** anime my mobs
*/

#include "my.h"

void anime_rmob(sfClock *clock, int j, mob_t *mob, int max_value)
{
    static sfIntRect rect = {0, 0, 300, 300};
    static int i = 0;
    static sfTime time;
    static float sec;

    time = sfClock_getElapsedTime(clock);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.05) {
        if (i == 0)
            rect.left = rect.left + j;
        else
            rect.left = rect.left - j;
        for (int i = 0; i != mob->red.nb_mob; i++)
            sfSprite_setTextureRect(mob->red.sprite[i], rect);
        if (rect.left >= max_value)
            i = 1;
        if (rect.left <= 0)
            i = 0;
        sfClock_restart(clock);
    }
}

void anime_gmob(sfClock *clock, int j, mob_t *mob, int max_value)
{
    static sfIntRect rect = {0, 10, 300, 300};
    static int i = 0;
    static sfTime time;
    static float sec;

    time = sfClock_getElapsedTime(clock);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.05) {
        if (i == 0)
            rect.left = rect.left + j;
        else
            rect.left = rect.left - j;
        for (int i = 0; i != mob->green.nb_mob; i++)
            sfSprite_setTextureRect(mob->green.sprite[i], rect);
        if (rect.left >= max_value)
            i = 1;
        if (rect.left <= 0)
            i = 0;
        sfClock_restart(clock);
    }
}

void anime_bmob(sfClock *clock, int j, mob_t *mob, int max_value)
{
    static sfIntRect rect = {0, -80, 200, 300};
    static int i = 0;
    static sfTime time;
    static float sec;

    time = sfClock_getElapsedTime(clock);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.02) {
        if (i == 0)
            rect.left = rect.left + j;
        else
            rect.left = rect.left - j;
        for (int i = 0; i != mob->black.nb_mob; i++)
            sfSprite_setTextureRect(mob->black.sprite[i], rect);
        if (rect.left >= max_value)
            i = 1;
        if (rect.left <= 0)
            i = 0;
        sfClock_restart(clock);
    }
}

void anime_grmob(sfClock *clock, int j, mob_t *mob, int max_value)
{
    static sfIntRect rect = {0, -20, 280, 300};
    static int i = 0;
    static sfTime time;
    static float sec;

    time = sfClock_getElapsedTime(clock);
    sec = time.microseconds / 1000000.0;
    if (sec > 0.05) {
        if (i == 0)
            rect.left = rect.left + j;
        else
            rect.left = rect.left - j;
        for (int i = 0; i != mob->grey.nb_mob; i++)
            sfSprite_setTextureRect(mob->grey.sprite[i], rect);
        if (rect.left >= max_value)
            i = 1;
        if (rect.left <= 0)
            i = 0;
        sfClock_restart(clock);
    }
}
