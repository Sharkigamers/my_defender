/*
** EPITECH PROJECT, 2019
** redmob.c
** File description:
** reate my redmob and anime him
*/

#include "my.h"

void start_drawing_all_mob(dwd_t *dwd, mob_t *mob, int *j)
{
    for (int i = 0; i < mob->red.nb_mob && *j == 1; i++) {
        if (dwd->cgame.sec[0] > 0.01) {
            mover_on_map(mob, mob->red.posspr, i, mob->red.check_posspr);
            sfClock_restart(dwd->cgame.clock[0]);
        }
        sfRenderWindow_drawSprite(dwd->window, mob->red.sprite[i], NULL);
        anime_rmob(mob->red.clock, 293, mob, 5567);
    }
    for (int i = 0; i < mob->green.nb_mob && *j == 1; i++) {
        if (dwd->cgame.sec[1] > 0.01) {
            moveg_on_map(mob, mob->green.posspr, i, mob->green.check_posspr);
            sfClock_restart(dwd->cgame.clock[1]);
        }
        sfRenderWindow_drawSprite(dwd->window, mob->green.sprite[i], NULL);
        anime_gmob(mob->green.clock, 345, mob, 6550);
    }
}

void draw_all_mob(dwd_t *dwd, mob_t *mob, int *j)
{
    start_drawing_all_mob(dwd, mob, j);
    for (int i = 0; i < mob->black.nb_mob && *j == 1; i++) {
        if (dwd->cgame.sec[2] > 0.01) {
            moveb_on_map(mob, mob->black.posspr, i, mob->black.check_posspr);
            sfClock_restart(dwd->cgame.clock[2]);
        }
        sfRenderWindow_drawSprite(dwd->window, mob->black.sprite[i], NULL);
        anime_bmob(mob->black.clock, 256, mob, 4608);
    }
    for (int i = 0; i < mob->grey.nb_mob && *j == 1; i++) {
        if (dwd->cgame.sec[3] > 0.01) {
            movegr_on_map(mob, mob->grey.posspr, i, mob->grey.check_posspr);
            sfClock_restart(dwd->cgame.clock[3]);
        }
        sfRenderWindow_drawSprite(dwd->window, mob->grey.sprite[i], NULL);
        anime_grmob(mob->grey.clock, 318, mob, 5818);
    }
}

void print_redmob(dwd_t *dwd, mob_t *mob)
{
    static int j = 0;
    static int a = 0;

    if (j == 0)
        sfRenderWindow_drawSprite(dwd->window, mob->init.icon, NULL);
    if (check_launch_wave(dwd, mob, j) == 1) {
        j = 1;
        if (a == 1) {
            next_wave(mob);
            a = 2;
        }
    }
    if (check_end_wave(mob) == 1) {
        j = 0;
        a = 1;
    }
    draw_all_mob(dwd, mob, &j);
}
