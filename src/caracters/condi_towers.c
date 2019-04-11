/*
** EPITECH PROJECT, 2019
** defender
** File description:
** condi_towers
*/

#include "my.h"

void arrow_tower_condi(int *life, sfVector2f pos, int i, to_t *to)
{
    sfVector2f posi = sfSprite_getPosition(to->construct.towers_s[i]);
    static float stock = 4;

    if (pos.x > posi.x - 200 &&
        pos.x < posi.x + 400 &&
        pos.y > posi.y - 200 &&
        pos.y < posi.y + 400
        && to->project.sec[i] > speed_increase(to, i)) {
        if (send_projectile(posi, pos, to, i) == 0) {
            if (*life > 0) {
                (*life) = (*life) - stock - speed_increase(to, i);
            }
            if (*life == 0)
                deal_money(5, to);
            sfClock_restart(to->project.clock[i]);
        }
    }
}

void bank_tower_condi(int i, to_t *to, int tower)
{
    if (to->bank.sec[i] > 0.4 && tower == 9) {
        to->construct.money = to->construct.money + 1;
        sfClock_restart(to->bank.clock[i]);
    }
    if (to->bank.sec[i] > 0.3 && tower == 10) {
        to->construct.money = to->construct.money + 1;
        sfClock_restart(to->bank.clock[i]);
    }
    if (to->bank.sec[i] > 0.2 && tower == 11) {
        to->construct.money = to->construct.money + 1;
        sfClock_restart(to->bank.clock[i]);
    }
    if (to->bank.sec[i] > 0.1 && tower == 12) {
        to->construct.money = to->construct.money + 1;
        sfClock_restart(to->bank.clock[i]);
    }
}

void mage_tower_condi(int *life, sfVector2f pos, int i, to_t *to)
{
    sfVector2f posi = sfSprite_getPosition(to->construct.towers_s[i]);
    int nb = 0;

    if (pos.x > posi.x - 100 &&
        pos.x < posi.x + 200 &&
        pos.y > posi.y - 100 &&
        pos.y < posi.y + 230
        && to->mage.sec[i] > 0.1 && nb == 0) {
        if (sendm_projectile(posi, pos, i, to) == 0) {
            if (*life > 0) {
                (*life)--;
            }
            if (*life == 0)
                deal_money(5, to);
            nb++;
            sfClock_restart(to->mage.clock[i]);
        }
    }
}

void moltar_tower_condi(int *life, sfVector2f pos, int i, to_t *to)
{
    sfVector2f posi = sfSprite_getPosition(to->construct.towers_s[i]);
    static int stock = 10;

    if (pos.x > posi.x - 200 &&
        pos.x < posi.x + 400 &&
        pos.y > posi.y - 200 &&
        pos.y < posi.y + 400
        && to->moltar.sec[i] > moltar_increase(to->tower[i])) {
        if (send_rock_projectile(posi, pos, i, to) == 0) {
            (*life) = (*life) - stock - moltar_increase(to->tower[i]);
            sfClock_restart(to->moltar.clock[i]);
            if (*life == 0)
                deal_money(5, to);
        }
    }
}
