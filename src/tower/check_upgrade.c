/*
** EPITECH PROJECT, 2019
** defender
** File description:
** check upgrade
*/

#include "my.h"

void annex_check_upgrade(int lvl, to_t *to)
{
    if (lvl >= 9 && lvl <= 12) {
        to->construct.rect_tower.left = 230 * (lvl - 8);
        to->construct.rect_tower.top = 770;
        to->construct.rect_tower.height = 211;
        to->construct.rect_tower.width = 226;
        sfSprite_setTextureRect(to->construct.towers_s[to->construct.pos_to],
                                to->construct.rect_tower);
    }
    if (lvl >= 13 && lvl <= 16) {
        to->construct.rect_tower.left = 230 * (lvl - 12);
        to->construct.rect_tower.top = 1005;
        to->construct.rect_tower.height = 257;
        to->construct.rect_tower.width = 202;
        sfSprite_setTextureRect(to->construct.towers_s[to->construct.pos_to],
                                to->construct.rect_tower);
    }
}

void check_upgrade(int lvl, to_t *to)
{
    if (lvl >= 1 && lvl <= 4) {
        to->construct.rect_tower.left = 230 * lvl;
        to->construct.rect_tower.top = 540;
        to->construct.rect_tower.height = 210;
        to->construct.rect_tower.width = 204;
        sfSprite_setTextureRect(to->construct.towers_s[to->construct.pos_to],
                                to->construct.rect_tower);
    }
    if (lvl >= 5 && lvl <= 8) {
        to->construct.rect_tower.left = 230 * (lvl - 4);
        to->construct.rect_tower.top = 286;
        to->construct.rect_tower.height = 217;
        to->construct.rect_tower.width = 206;
        sfSprite_setTextureRect(to->construct.towers_s[to->construct.pos_to],
                                to->construct.rect_tower);
    }
    annex_check_upgrade(lvl, to);
}

void check_price(int lvl, to_t *to)
{
    if (lvl >= 1 && lvl < 4)
        to->money.upg_money = 72 * (1.5 * lvl);
    if (lvl >= 5 && lvl < 8)
        to->money.upg_money = 120 * (1.2 * (lvl - 4));
    if (lvl >= 9 && lvl < 12)
        to->money.upg_money = 100 * (1.2 * (lvl - 8));
    if (lvl >= 13 && lvl < 16)
        to->money.upg_money = 150 * (1.3 * (lvl - 12));
}
