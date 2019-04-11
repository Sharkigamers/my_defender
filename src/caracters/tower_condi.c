/*
** EPITECH PROJECT, 2019
** tower_condi.c
** File description:
** create my shot conditions for my towers
*/

#include "my.h"

void change_to_big_arrow(int i, to_t *to)
{
    sfTexture *text;
    sfVector2f scl;
    static int a = 0;

    if (a == 0) {
        scl.x = 1;
        scl.y = 1;
        text = sfTexture_createFromFile("./assets/gameplay/bigarrow.png", NULL);
        sfSprite_setTexture(to->project.arrow[i], text, sfTrue);
        sfSprite_setScale(to->project.arrow[i], scl);
        a++;
    }
}

float speed_increase(to_t *to, int i)
{
    if (to->tower[i] == 1)
        return (2);
    if (to->tower[i] == 2)
        return (1);
    if (to->tower[i] == 3)
        return (0.8);
    if (to->tower[i] == 4) {
        return (0.5);
    }
    return (10);
}

float moltar_increase(int i)
{
    if (i == 5)
        return (5);
    if (i == 6)
        return (4);
    if (i == 7)
        return (3);
    if (i == 8) {
        return (2);
    }
    return (10);
}
