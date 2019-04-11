/*
** EPITECH PROJECT, 2019
** defender
** File description:
** cond dmg spell
*/

#include "my.h"

void sec_cond_acid(mob_t *mob, sfVector2f pos)
{
    for (int i = 0; i != mob->black.nb_mob; i++) {
        if (mob->black.posspr[i].x >= pos.x - 100 &&
            mob->black.posspr[i].x <= pos.x + 100 &&
            mob->black.posspr[i].y >= pos.y - 50 &&
            mob->black.posspr[i].y <= pos.y + 100) {
            mob->black.posspr[i].x = mob->black.posspr[i].x - 7.5;
            mob->black.posspr[i].y = mob->black.posspr[i].y - 7.5;
            mob->black.life[i] = mob->black.life[i] - 2;
        }
    }
    for (int i = 0; i != mob->grey.nb_mob; i++) {
        if (mob->grey.posspr[i].x >= pos.x - 100 &&
            mob->grey.posspr[i].x <= pos.x + 100 &&
            mob->grey.posspr[i].y >= pos.y - 50 &&
            mob->grey.posspr[i].y <= pos.y + 100) {
            mob->grey.posspr[i].x = mob->grey.posspr[i].x - 7.5;
            mob->grey.posspr[i].y = mob->grey.posspr[i].y - 7.5;
            mob->grey.life[i] = mob->grey.life[i] - 2;
        }
    }
}

void cond_acid(mob_t *mob, sfVector2f pos)
{
    for (int i = 0; i != mob->green.nb_mob; i++) {
        if (mob->green.posspr[i].x >= pos.x - 100 &&
            mob->green.posspr[i].x <= pos.x + 100 &&
            mob->green.posspr[i].y >= pos.y - 50 &&
            mob->green.posspr[i].y <= pos.y + 100) {
            mob->green.life[i] = mob->green.life[i] - 2;
            mob->green.posspr[i].x = mob->green.posspr[i].x - 7.5;
            mob->green.posspr[i].y = mob->green.posspr[i].y - 7.5;
        }
    }
}

void check_hitbox_acid(sfSprite *sprite, mob_t *mob)
{
    sfVector2f pos = sfSprite_getPosition(sprite);

    for (int i = 0; i != mob->red.nb_mob; i++) {
        if (mob->red.posspr[i].x >= pos.x - 100 &&
            mob->red.posspr[i].x <= pos.x + 100 &&
            mob->red.posspr[i].y >= pos.y - 50 &&
            mob->red.posspr[i].y <= pos.y + 100) {
            mob->red.life[i] = mob->red.life[i] - 2;
            mob->red.posspr[i].x = mob->red.posspr[i].x - 7.5;
            mob->red.posspr[i].y = mob->red.posspr[i].y - 7.5;
        }
    }
    cond_acid(mob, pos);
    sec_cond_acid(mob, pos);
}
