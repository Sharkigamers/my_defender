/*
** EPITECH PROJECT, 2019
** init_life_mob.c
** File description:
** init all my mobs lifes
*/

#include "my.h"

void init_life_mob(mob_t *mob)
{
    mob->red.life = malloc(sizeof(int) * 100);
    for (int i = 0; i <= mob->red.nb_mob; i++)
        mob->red.life[i] = 3;
    mob->green.life = malloc(sizeof(int) * 100);
    for (int i = 0; i <= mob->green.nb_mob; i++)
        mob->green.life[i] = 6;
    mob->black.life = malloc(sizeof(int) * 100);
    for (int i = 0; i <= mob->black.nb_mob; i++)
        mob->black.life[i] = 2;
    mob->grey.life = malloc(sizeof(int) * 100);
    for (int i = 0; i <= mob->grey.nb_mob; i++)
        mob->grey.life[i] = 10;
}

void fill_life_mob(mob_t *mob)
{
    static int l = 0;

    for (int i = 0; i != mob->red.nb_mob; i++)
        mob->red.life[i] = 3 + l;
    for (int i = 0; i != mob->green.nb_mob; i++)
        mob->green.life[i] = 6 + l;
    for (int i = 0; i != mob->black.nb_mob; i++)
        mob->black.life[i] = 2 + l;
    for (int i = 0; i != mob->grey.nb_mob; i++)
        mob->grey.life[i] = 10 + l;
    l++;
}
