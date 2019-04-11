/*
** EPITECH PROJECT, 2019
** defender
** File description:
** cond_wave
*/

#include "my.h"

void start_check_end_wave(mob_t *mob)
{
    for (int i = 0; i < mob->red.nb_mob; i++) {
        if (mob->red.posspr[i].x > 1890 && mob->red.posspr[i].y < 1080) {
            mob->red.posspr[i].y = 1500;
            sfSprite_setPosition(mob->red.sprite[i], mob->red.posspr[i]);
            mob->life.life--;
        }
    }
    for (int i = 0; i < mob->green.nb_mob; i++) {
        if (mob->green.posspr[i].x > 1890 && mob->green.posspr[i].y < 1080) {
            mob->green.posspr[i].y = 1500;
            sfSprite_setPosition(mob->green.sprite[i], mob->green.posspr[i]);
            mob->life.life--;
        }
    }
}

int check_end_wave(mob_t *mob)
{
    check_lose_life(mob, mob->life.life);
    start_check_end_wave(mob);
    for (int i = 0; i < mob->black.nb_mob; i++) {
        if (mob->black.posspr[i].x > 1890 && mob->black.posspr[i].y < 1080) {
            mob->black.posspr[i].y = 1500;
            sfSprite_setPosition(mob->black.sprite[i], mob->black.posspr[i]);
            mob->life.life--;
        }
    }
    for (int i = 0; i < mob->grey.nb_mob; i++) {
        if (mob->grey.posspr[i].x > 1890 && mob->grey.posspr[i].y < 1080) {
            mob->grey.posspr[i].y = 1500;
            sfSprite_setPosition(mob->grey.sprite[i], mob->grey.posspr[i]);
            mob->life.life--;
        }
    }
    if (check_enemy_alive(mob) == 0)
        return (1);
    return (0);
}

void next_wave(mob_t *mob)
{
    free_wave(mob);
    create_wave(mob);
    fill_life_mob(mob);
}

int check_launch_wave(dwd_t *dwd, mob_t *mob, int j)
{
    sfVector2f pos = sfSprite_getPosition(mob->init.icon);

    if (dwd->mouse.pos.x > pos.x - 0 &&
        dwd->mouse.pos.x < pos.x + 70 &&
        dwd->mouse.pos.y > pos.y - 0 &&
        dwd->mouse.pos.y < pos.y + 70) {
        if (j == 0)
            sfRenderWindow_drawSprite(dwd->window, mob->init.iconh, NULL);
        if (dwd->event.type == sfEvtMouseButtonPressed)
            return (1);
    }
    return (0);
}
