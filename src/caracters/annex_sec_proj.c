/*
** EPITECH PROJECT, 2019
** defender
** File description:
** annex_sec_proj
*/

#include "my.h"

int send_projectile(sfVector2f postower, sfVector2f pos, to_t *to, int i)
{
    static int a = 0;

    if (a == 0) {
        to->project.pos_arrow[i] = postower;
        a++;
    }
    annex_project(i, to, pos);
    if (annex_send_projectile(i, to, &a, pos) == 0)
        return (0);
    if (to->project.pos_arrow[i].x < postower.x - 200
        || to->project.pos_arrow[i].x > postower.x + 400 ||
        to->project.pos_arrow[i].y < postower.y - 200
        || to->project.pos_arrow[i].y > postower.y + 400) {
        to->project.pos_arrow[i].y = 5000;
        sfSprite_setPosition(to->project.arrow[i], to->project.pos_arrow[i]);
        a = 0;
        return (1);
    }
    return (1);
}

void annex_project(int i, to_t *to, sfVector2f pos)
{
    if (to->project.secm[i] > 0.01) {
        move_to_pos
            (&to->project.pos_arrow[i], pos, 15, &to->project.angle_arrow[i]);
        sfSprite_setRotation(to->project.arrow[i], to->project.angle_arrow[i]);
        sfSprite_setPosition(to->project.arrow[i], to->project.pos_arrow[i]);
        if (to->project.secm[i] > 0.02)
            sfClock_restart(to->project.clockm[i]);
    }
}

int annex_send_projectile(int i, to_t *to, int *a, sfVector2f pos)
{
    if (to->project.pos_arrow[i].x >= pos.x - 5 &&
        to->project.pos_arrow[i].x <= pos.x + 30 &&
        to->project.pos_arrow[i].y >= pos.y - 20 &&
        to->project.pos_arrow[i].y <= pos.y + 60) {
        to->project.pos_arrow[i].y = 5000;
        sfSprite_setPosition(to->project.arrow[i], to->project.pos_arrow[i]);
        *a = 0;
        return (0);
    }
    return (1);
}

void annex_send_rock(int i, to_t *to, sfVector2f *posr, sfVector2f pos)
{
    if (to->moltar.secm[i] > 0.01) {
        move_to_posr(posr, pos, 10);
        sfSprite_setPosition(to->moltar.rock[i], *posr);
        sfClock_restart(to->moltar.clockm[i]);
    }
}

int send_rock_projectile(sfVector2f postower, sfVector2f pos, int i, to_t *to)
{
    static sfVector2f posr;
    static int a = 0;

    if (a == 0) {
        posr.x = postower.x + 65;
        posr.y = postower.y;
        a++;
    }
    annex_send_rock(i, to, &posr, pos);
    if (posr.x >= pos.x - 50 &&
        posr.x <= pos.x + 30 &&
        posr.y >= pos.y - 20 &&
        posr.y <= pos.y + 60) {
        posr.y = 5000;
        sfSprite_setPosition(to->moltar.rock[i], posr);
        a = 0;
        return (0);
    }
    return (1);
}
