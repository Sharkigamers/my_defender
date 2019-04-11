/*
** EPITECH PROJECT, 2019
** defender
** File description:
** disp spell
*/

#include "my.h"

void disp_dropped_spell_one(mob_t *mob, dwd_t *dwd)
{
    mob->spell.time[0] = sfClock_getElapsedTime(mob->spell.clock[0]);
    mob->spell.sec[0] = mob->spell.time[0].microseconds / 1000000.0;
    if (mob->spell.is_click[0] == -1) {
        if (mob->spell.rect_spell1.top == 750) {
            mob->spell.rect_spell1.left = 55 - 95;
            mob->spell.rect_spell1.top = 50;
            mob->spell.rect_spell1.height = 150;
            mob->spell.rect_spell1.width = 90;
        }
        if (mob->spell.rect_spell1.left < 1430 && mob->spell.sec[0] > 0.05) {
            mob->spell.rect_spell1.left += 95;
            check_hitbox_fire(mob->spell.spell1_s, mob);
            sfSprite_setTextureRect
                (mob->spell.spell1_s, mob->spell.rect_spell1);
            sfClock_restart(mob->spell.clock[0]);
        }
        sfRenderWindow_drawSprite(dwd->window, mob->spell.spell1_s, NULL);
    }
}

void cond_disp_dropped_spell_two(mob_t *mob)
{
    if (mob->spell.rect_spell2.top == 790) {
        mob->spell.rect_spell2.left = 26 - 138;
        mob->spell.rect_spell2.top = 260;
        mob->spell.rect_spell2.height = 140;
        mob->spell.rect_spell2.width = 144;
    }
}

void disp_dropped_spell_two(mob_t *mob, dwd_t *dwd)
{
    mob->spell.time[1] = sfClock_getElapsedTime(mob->spell.clock[1]);
    mob->spell.sec[1] = mob->spell.time[1].microseconds / 1000000.0;
    if (mob->spell.is_click[1] == -2) {
        cond_disp_dropped_spell_two(mob);
        if (mob->spell.rect_spell2.left > 1250 && mob->spell.sec[1] < 2) {
            sfRenderWindow_drawSprite(dwd->window, mob->spell.spell2_s, NULL);
            return;
        }
        if (mob->spell.rect_spell2.left < 1430 && mob->spell.sec[1] > 0.1) {
            mob->spell.rect_spell2.left += 138;
            check_hitbox_snow(mob->spell.spell2_s, mob);
            sfSprite_setTextureRect
                (mob->spell.spell2_s, mob->spell.rect_spell2);
            sfClock_restart(mob->spell.clock[1]);
        }
        sfRenderWindow_drawSprite(dwd->window, mob->spell.spell2_s, NULL);
    }
}

void cond_disp_spell_tree(mob_t *mob)
{
    static int nb_rep = 0;

    if (mob->spell.rect_spell3.left > 860 && nb_rep != 3) {
        mob->spell.rect_spell3.left = 152;
        nb_rep++;
    }
    if (mob->spell.rect_spell3.left < 1430 && mob->spell.sec[2] > 0.15) {
        mob->spell.rect_spell3.left += 147;
        sfSprite_setTextureRect(mob->spell.spell3_s, mob->spell.rect_spell3);
        check_hitbox_acid(mob->spell.spell3_s, mob);
        sfClock_restart(mob->spell.clock[2]);
    }
    if (nb_rep == 3) {
        nb_rep = 0;
        mob->spell.is_click[2] = 0;
    }
}

void disp_dropped_spell_tree(mob_t *mob, dwd_t *dwd)
{
    mob->spell.time[2] = sfClock_getElapsedTime(mob->spell.clock[2]);
    mob->spell.sec[2] = mob->spell.time[2].microseconds / 1000000.0;
    if (mob->spell.is_click[2] == -3) {
        if (mob->spell.rect_spell3.top == 684) {
            mob->spell.rect_spell3.left = 5 - 147;
            mob->spell.rect_spell3.top = 478;
            mob->spell.rect_spell3.height = 192;
            mob->spell.rect_spell3.width = 142;
        }
        cond_disp_spell_tree(mob);
        sfRenderWindow_drawSprite(dwd->window, mob->spell.spell3_s, NULL);
    }
}
