/*
** EPITECH PROJECT, 2019
** dmg_spell.C
** File description:
** create all my damages for my spells
*/

#include "my.h"

void cond_fire(mob_t *mob, sfVector2f pos)
{
    for (int i = 0; i != mob->black.nb_mob; i++) {
        if (mob->black.posspr[i].x >= pos.x - 100 &&
            mob->black.posspr[i].x <= pos.x + 100 &&
            mob->black.posspr[i].y >= pos.y - 50 &&
            mob->black.posspr[i].y <= pos.y + 100)
            mob->black.life[i] = mob->black.life[i] - 15;
    }
    for (int i = 0; i != mob->grey.nb_mob; i++) {
        if (mob->grey.posspr[i].x >= pos.x - 100 &&
            mob->grey.posspr[i].x <= pos.x + 100 &&
            mob->grey.posspr[i].y >= pos.y - 50 &&
            mob->grey.posspr[i].y <= pos.y + 100)
            mob->grey.life[i] = mob->grey.life[i] - 15;
    }
}

void check_hitbox_fire(sfSprite *sprite, mob_t *mob)
{
    sfVector2f pos = sfSprite_getPosition(sprite);

    for (int i = 0; i != mob->red.nb_mob; i++) {
        if (mob->red.posspr[i].x >= pos.x - 100 &&
            mob->red.posspr[i].x <= pos.x + 100 &&
            mob->red.posspr[i].y >= pos.y - 50 &&
            mob->red.posspr[i].y <= pos.y + 100)
            mob->red.life[i] = mob->red.life[i] - 15;
    }
    for (int i = 0; i != mob->green.nb_mob; i++) {
        if (mob->green.posspr[i].x >= pos.x - 100 &&
            mob->green.posspr[i].x <= pos.x + 100 &&
            mob->green.posspr[i].y >= pos.y - 50 &&
            mob->green.posspr[i].y <= pos.y + 100)
            mob->green.life[i] = mob->green.life[i] - 15;
    }
    cond_fire(mob, pos);
}

void sec_cond_snow(mob_t *mob, sfVector2f pos)
{
    for (int i = 0; i != mob->black.nb_mob; i++) {
        if (mob->black.posspr[i].x >= pos.x - 100 &&
            mob->black.posspr[i].x <= pos.x + 100 &&
            mob->black.posspr[i].y >= pos.y - 50 &&
            mob->black.posspr[i].y <= pos.y + 100) {
            mob->black.posspr[i].x = mob->black.posspr[i].x - 10.1;
            mob->black.posspr[i].y = mob->black.posspr[i].y - 10.1;
        }
    }
    for (int i = 0; i != mob->grey.nb_mob; i++) {
        if (mob->grey.posspr[i].x >= pos.x - 100 &&
            mob->grey.posspr[i].x <= pos.x + 100 &&
            mob->grey.posspr[i].y >= pos.y - 50 &&
            mob->grey.posspr[i].y <= pos.y + 100) {
            mob->grey.posspr[i].x = mob->grey.posspr[i].x - 10.1;
            mob->grey.posspr[i].y = mob->grey.posspr[i].y - 10.1;
        }
    }
}

void cond_snow(mob_t *mob, sfVector2f pos)
{
    for (int i = 0; i != mob->green.nb_mob; i++) {
        if (mob->green.posspr[i].x >= pos.x - 100 &&
            mob->green.posspr[i].x <= pos.x + 100 &&
            mob->green.posspr[i].y >= pos.y - 50 &&
            mob->green.posspr[i].y <= pos.y + 100) {
            mob->green.posspr[i].x = mob->green.posspr[i].x - 10.26;
            mob->green.posspr[i].y = mob->green.posspr[i].y - 10.26;
        }
    }
}
void check_hitbox_snow(sfSprite *sprite, mob_t *mob)
{
    sfVector2f pos = sfSprite_getPosition(sprite);

    for (int i = 0; i != mob->red.nb_mob; i++) {
        if (mob->red.posspr[i].x >= pos.x - 100 &&
            mob->red.posspr[i].x <= pos.x + 100 &&
            mob->red.posspr[i].y >= pos.y - 50 &&
            mob->red.posspr[i].y <= pos.y + 100) {
            mob->red.posspr[i].x = mob->red.posspr[i].x - 10.5;
            mob->red.posspr[i].y = mob->red.posspr[i].y - 10.5;
        }
    }
    cond_snow(mob, pos);
    sec_cond_snow(mob, pos);
}
