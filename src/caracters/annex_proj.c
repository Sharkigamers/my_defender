/*
** EPITECH PROJECT, 2019
** defender
** File description:
** annex_proj
*/

#include "my.h"

float speedm_increase(int i)
{
    if (i == 13)
        return (2);
    if (i == 14)
        return (1.5);
    if (i == 15)
        return (1);
    if (i == 16)
        return (0.8);
    return (10);
}

void first_cond(int *a, sfVector2f postower, sfVector2f *posi)
{
    if (a == 0) {
        (*posi).x = postower.x + 220;
        (*posi).y = postower.y + 140;
        (*a)++;
    }
}

void second_cond
(sfVector2f postower, sfVector2f *posi, sfVector2f pos, float *angle)
{
    if (postower.x < pos.x) {
        (*posi).x = postower.x + 220;
        (*posi).y = postower.y + 140;
        *angle = 140;
    }
    if (postower.x > pos.x) {
        *angle = -140;
        (*posi).x = postower.x + 30;
        (*posi).y = postower.y + 180;
    }
}

int sendm_projectile(sfVector2f postower, sfVector2f pos, int i, to_t *to)
{
    static sfVector2f posi;
    static float angle = 0;
    static int a = 0;

    first_cond(&a, postower, &posi);
    second_cond(postower, &posi, pos, &angle);
    sfSprite_setPosition(to->mage.spell[i], posi);
    sfSprite_setRotation(to->mage.spell[i], angle);
    if (angle != 0 && to->mage.secm[i] > speedm_increase(to->tower[i])) {
        angle = 140;
        posi.y = 5000;
        a = 0;
        sfSprite_setPosition(to->mage.spell[i], posi);
        sfClock_restart(to->mage.clockm[i]);
        return (0);
    }
    return (1);
}
