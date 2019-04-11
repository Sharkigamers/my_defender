/*
** EPITECH PROJECT, 2019
** move_on_map.c
** File description:
** move my mob on my map
*/

#include "my.h"

void mover_on_map(mob_t *mob, sfVector2f *pos, int i, int *map)
{
    if (pos[i].x < 1920 && pos[i].y < 1080 && pos[i].y > -40) {
        if (pos[i].x < mob->init.pos[map[i]].x)
            pos[i].x = pos[i].x + 1.5;
        if (pos[i].y > mob->init.pos[map[i]].y)
            pos[i].y = pos[i].y - 1.5;
        if (pos[i].y < mob->init.pos[map[i]].y)
            pos[i].y = pos[i].y + 1.5;
        sfSprite_setPosition(mob->red.sprite[i], pos[i]);
        if (pos[i].x >= mob->init.pos[map[i]].x - 1 &&
            pos[i].y >= mob->init.pos[map[i]].y - 2 &&
            pos[i].y <= mob->init.pos[map[i]].y + 2) {
            map[i] = map[i] + 1;
        }
    }
}

void moveg_on_map(mob_t *mob, sfVector2f *pos, int i, int *map)
{
    if (pos[i].x < 1920 && pos[i].y < 1080 && pos[i].y > -40) {
        if (pos[i].x < mob->init.pos[map[i]].x)
            pos[i].x = pos[i].x + 1.26;
        if (pos[i].y > mob->init.pos[map[i]].y)
            pos[i].y = pos[i].y - 1.26;
        if (pos[i].y < mob->init.pos[map[i]].y)
            pos[i].y = pos[i].y + 1.26;
        sfSprite_setPosition(mob->green.sprite[i], pos[i]);
        if (pos[i].x >= mob->init.pos[map[i]].x - 1 &&
            pos[i].y >= mob->init.pos[map[i]].y - 2 &&
            pos[i].y <= mob->init.pos[map[i]].y + 2) {
            map[i] = map[i] + 1;
        }
    }
}

void moveb_on_map(mob_t *mob, sfVector2f *pos, int i, int *map)
{
    if (pos[i].x < 1920 && pos[i].y < 1080 && pos[i].y > -40) {
        if (pos[i].x < mob->init.pos[map[i]].x)
            pos[i].x = pos[i].x + 2.1;
        if (pos[i].y > mob->init.pos[map[i]].y)
            pos[i].y = pos[i].y - 2.1;
        if (pos[i].y < mob->init.pos[map[i]].y)
            pos[i].y = pos[i].y + 2.1;
        sfSprite_setPosition(mob->black.sprite[i], pos[i]);
        if (pos[i].x >= mob->init.pos[map[i]].x - 5 &&
            pos[i].y >= mob->init.pos[map[i]].y - 10 &&
            pos[i].y <= mob->init.pos[map[i]].y + 10) {
            map[i] = map[i] + 1;
        }
    }
}

void movegr_on_map(mob_t *mob, sfVector2f *pos, int i, int *map)
{
    if (pos[i].x < 1920 && pos[i].y < 1080 && pos[i].y > -40) {
        if (pos[i].x < mob->init.pos[map[i]].x)
            pos[i].x = pos[i].x + 0.9;
        if (pos[i].y > mob->init.pos[map[i]].y)
            pos[i].y = pos[i].y - 0.9;
        if (pos[i].y < mob->init.pos[map[i]].y)
            pos[i].y = pos[i].y + 0.9;
        sfSprite_setPosition(mob->grey.sprite[i], pos[i]);
        if (pos[i].x >= mob->init.pos[map[i]].x - 5 &&
            pos[i].y >= mob->init.pos[map[i]].y - 10 &&
            pos[i].y <= mob->init.pos[map[i]].y + 10) {
            map[i] = map[i] + 1;
        }
    }
}
