/*
** EPITECH PROJECT, 2019
** defender
** File description:
** for the forest map
*/

#include "my.h"

int check_pos(to_t *to, int type_tower, sfVector2f pos)
{
    if (pos.x == 304 && pos.y == 49) {
        to->tower[0] = type_tower;
        return (0);
    }
    if (pos.x == 588 && pos.y == 300) {
        to->tower[1] = type_tower;
        return (1);
    }
    if (pos.x == 720 && pos.y == 509) {
        to->tower[2] = type_tower;
        return (2);
    }
    if (pos.x == 870 && pos.y == 302) {
        to->tower[3] = type_tower;
        return (3);
    }
    return (annex_check_pos(to, type_tower, pos));
}

void forest_constrcut(to_t *to, dwd_t *dwd)
{
    if (to->tower[0] == 0)
        construction(386, 156, to, dwd);
    if (to->tower[1] == 0)
        construction(670, 407, to, dwd);
    if (to->tower[2] == 0)
        construction(802, 616, to, dwd);
    if (to->tower[3] == 0)
        construction(952, 409, to, dwd);
    if (to->tower[4] == 0)
        construction(1233, 403, to, dwd);
    if (to->tower[5] == 0)
        construction(1578, 410, to, dwd);
}

void forest_upgrade(to_t *to, dwd_t *dwd)
{
    if (to->tower[0] > 0)
        show_upgrade(386, 156, to, dwd);
    if (to->tower[1] > 0)
        show_upgrade(670, 407, to, dwd);
    if (to->tower[2] > 0)
        show_upgrade(802, 616, to, dwd);
    if (to->tower[3] > 0)
        show_upgrade(952, 409, to, dwd);
    if (to->tower[4] > 0)
        show_upgrade(1233, 403, to, dwd);
    if (to->tower[5] > 0)
        show_upgrade(1578, 410, to, dwd);
}

void buy_tower(dwd_t *dwd, to_t *to, sfVector2f get_pos)
{
    buy_arc_tower(dwd, to, get_pos);
    buy_cannon_tower(dwd, to, get_pos);
    buy_def_tower(dwd, to, get_pos);
    buy_mage_tower(dwd, to, get_pos);
}

int witch_to(int xmin, int ymin)
{
    if ((xmin == 386 && ymin == 156) || (xmin == 304 && ymin == 49))
        return (0);
    if ((xmin == 670 && ymin == 407) || (xmin == 588 && ymin == 300))
        return (1);
    if ((xmin == 802 && ymin == 616) || (xmin == 720 && ymin == 509))
        return (2);
    if ((xmin == 952 && ymin == 409) || (xmin == 870 && ymin == 302))
        return (3);
    if ((xmin == 1233 && ymin == 403) || (xmin == 1151 && ymin == 296))
        return (4);
    else
        return (5);
}
