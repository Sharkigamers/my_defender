/*
** EPITECH PROJECT, 2019
** send_projectile.c
** File description:
** create my function who send my projectiles
*/

#include "my.h"

void move_to_pos(sfVector2f *move, sfVector2f to, float speed, float *angle)
{
    if (move->x < to.x) {
        move->x = move->x + speed;
        *angle = 135;
    }
    if (move->x > to.x) {
        move->x = move->x - speed;
        *angle = -45;
    }
    if (move->y < to.y)
        move->y = move->y + speed;
    if (move->y > to.y)
        move->y = move->y - speed;
}

void move_to_posr(sfVector2f *move, sfVector2f to, float speed)
{
    if (move->x < to.x) {
        move->x = move->x + speed;
    }
    if (move->x > to.x) {
        move->x = move->x - speed;
    }
    if (move->y < to.y)
        move->y = move->y + speed;
    if (move->y > to.y)
        move->y = move->y - speed;
}
