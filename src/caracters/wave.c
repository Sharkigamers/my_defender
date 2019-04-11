/*
** EPITECH PROJECT, 2019
** wave.c
** File description:
** create my waves function
*/

#include "my.h"

void malloc_wave(mob_t *mob)
{
    mob->red.posspr = malloc(sizeof(sfVector2f) * mob->red.nb_mob);
    mob->red.check_posspr = malloc(sizeof(int) * mob->red.nb_mob);
    mob->green.posspr = malloc(sizeof(sfVector2f) * mob->green.nb_mob);
    mob->green.check_posspr = malloc(sizeof(int) * mob->green.nb_mob);
    mob->black.posspr = malloc(sizeof(sfVector2f) * mob->black.nb_mob);
    mob->black.check_posspr = malloc(sizeof(int) * mob->black.nb_mob);
    mob->grey.posspr = malloc(sizeof(sfVector2f) * mob->grey.nb_mob);
    mob->grey.check_posspr = malloc(sizeof(int) * mob->grey.nb_mob);
}

void annex_create_wave(mob_t *mob)
{
    for (int i = 0; i < mob->black.nb_mob; i++) {
        mob->black.posspr[i].x = -10 - i * 50;
        mob->black.posspr[i].y = 10;
        mob->black.check_posspr[i] = 0;
    }
    for (int i = 0; i < mob->grey.nb_mob; i++) {
        mob->grey.posspr[i].x = -10 - i * 40;
        mob->grey.posspr[i].y = 10;
        mob->grey.check_posspr[i] = 0;
    }
}

void create_wave(mob_t *mob)
{
    malloc_wave(mob);
    for (int i = 0; i < mob->red.nb_mob; i++) {
        mob->red.posspr[i].x = -30 - i * 100;
        mob->red.posspr[i].y = 0;
        mob->red.check_posspr[i] = 0;
    }
    for (int i = 0; i < mob->green.nb_mob; i++) {
        mob->green.posspr[i].x = -10 - i * 123;
        mob->green.posspr[i].y = 0;
        mob->green.check_posspr[i] = 0;
    }
    annex_create_wave(mob);
}

void free_wave(mob_t *mob)
{
    free(mob->red.posspr);
    free(mob->red.check_posspr);
    free(mob->green.posspr);
    free(mob->green.check_posspr);
    free(mob->black.posspr);
    free(mob->black.check_posspr);
    free(mob->grey.posspr);
    free(mob->grey.check_posspr);
    mob->red.nb_mob = mob->red.nb_mob + 3;
    mob->green.nb_mob = mob->green.nb_mob + 2;
    mob->black.nb_mob = mob->black.nb_mob + 2;
    mob->grey.nb_mob = mob->grey.nb_mob + 1;
}

int check_enemy_alive(mob_t *mob)
{
    int alive = 0;

    for (int i = 0; i < mob->green.nb_mob; i++) {
        if (mob->green.posspr[i].x > -500 && mob->green.posspr[i].y < 1080)
            alive++;
    }
    for (int i = 0; i < mob->red.nb_mob; i++) {
        if (mob->red.posspr[i].x > - 500 && mob->red.posspr[i].y < 1080)
            alive++;
    }
    for (int i = 0; i < mob->black.nb_mob; i++) {
        if (mob->black.posspr[i].x > -500 && mob->black.posspr[i].y < 1080)
            alive++;
    }
    for (int i = 0; i < mob->grey.nb_mob; i++) {
        if (mob->grey.posspr[i].x > -500 && mob->grey.posspr[i].y < 1080)
            alive++;
    }
    return (alive);
}
