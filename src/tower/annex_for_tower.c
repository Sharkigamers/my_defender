/*
** EPITECH PROJECT, 2019
** defender
** File description:
** annex_for_tower
*/

#include "my.h"

int annex_check_pos(to_t *to, int type_tower, sfVector2f pos)
{
    if (pos.x == 1151 && pos.y == 296) {
        to->tower[4] = type_tower;
        return (4);
    }
    if (pos.x == 1496 && pos.y == 303)
        to->tower[5] = type_tower;
    return (5);
}
