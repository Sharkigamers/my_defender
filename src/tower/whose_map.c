/*
** EPITECH PROJECT, 2019
** defender
** File description:
** whose map
*/

#include "my.h"

void whose_construction_map(to_t *to, dwd_t *dwd)
{
    if (dwd->is_open == 10) {
        forest_constrcut(to, dwd);
        forest_upgrade(to, dwd);
    }
}

void disp_towers(to_t *to, dwd_t *dwd)
{
    for (int i = 0; to->tower[i] != -1; i++) {
        to->tower[i] != 0 ? sfRenderWindow_drawSprite
            (dwd->window, to->construct.towers_s[i], NULL) : 0;
    }
}
