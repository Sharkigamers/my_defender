/*
** EPITECH PROJECT, 2019
** defender
** File description:
** annex for building towers
*/

#include "my.h"

void buy_arc_tower(dwd_t *dwd, to_t *to, sfVector2f spos)
{
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        to->construct.money >= 70 && to->construct.is_click == 1 &&
        dwd->mouse.mouse_pos.x > spos.x + 9 && dwd->mouse.mouse_pos.x <
        spos.x + 93 && dwd->mouse.mouse_pos.y > spos.y + 36 &&
        dwd->mouse.mouse_pos.y < spos.y + 105) {
        to->construct.is_bought = check_pos(to, 1, spos);
        to->construct.rect_tower.left = 0;
        to->construct.rect_tower.top = 540;
        to->construct.rect_tower.height = 210;
        to->construct.rect_tower.width = 204;
        to->construct.pos_tower.x = spos.x + 15;
        to->construct.pos_tower.y = spos.y - 35;
        sfSprite_setTextureRect(to->construct.towers_s[to->construct.is_bought],
                                to->construct.rect_tower);
        sfSprite_setPosition(to->construct.towers_s[to->construct.is_bought],
                            to->construct.pos_tower);
        to->construct.money -= 70;
        to->construct.is_click = 0;
        dwd->event.type = 0;
    }
}

void buy_cannon_tower(dwd_t *dwd, to_t *to, sfVector2f spos)
{
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        to->construct.money >= 120 && to->construct.is_click == 1 &&
        dwd->mouse.mouse_pos.x > spos.x + 160 && dwd->mouse.mouse_pos.x <
        spos.x + 242 && dwd->mouse.mouse_pos.y > spos.y + 38 &&
        dwd->mouse.mouse_pos.y < spos.y + 105) {
        to->construct.is_bought = check_pos(to, 5, spos);
        to->construct.rect_tower.left = 0;
        to->construct.rect_tower.top = 286;
        to->construct.rect_tower.height = 217;
        to->construct.rect_tower.width = 206;
        to->construct.pos_tower.x = spos.x + 35;
        to->construct.pos_tower.y = spos.y - 30;
        sfSprite_setTextureRect(to->construct.towers_s[to->construct.is_bought],
                                to->construct.rect_tower);
        sfSprite_setPosition(to->construct.towers_s[to->construct.is_bought],
                            to->construct.pos_tower);
        to->construct.money -= 120;
        to->construct.is_click = 0;
        dwd->event.type = 0;
    }
}

void buy_def_tower(dwd_t *dwd, to_t *to, sfVector2f spos)
{
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        to->construct.money >= 100 && to->construct.is_click == 1 &&
        dwd->mouse.mouse_pos.x > spos.x + 11 && dwd->mouse.mouse_pos.x <
        spos.x + 93 && dwd->mouse.mouse_pos.y > spos.y + 156 &&
        dwd->mouse.mouse_pos.y < spos.y + 224) {
        to->construct.is_bought = check_pos(to, 9, spos);
        to->construct.rect_tower.left = 0;
        to->construct.rect_tower.top = 770;
        to->construct.rect_tower.height = 211;
        to->construct.rect_tower.width = 226;
        to->construct.pos_tower.x = spos.x + 15;
        to->construct.pos_tower.y = spos.y - 30;
        sfSprite_setTextureRect(to->construct.towers_s[to->construct.is_bought],
                                to->construct.rect_tower);
        sfSprite_setPosition(to->construct.towers_s[to->construct.is_bought],
                            to->construct.pos_tower);
        to->construct.money -= 100;
        to->construct.is_click = 0;
        dwd->event.type = 0;
    }
}

void buy_mage_tower(dwd_t *dwd, to_t *to, sfVector2f spos)
{
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        to->construct.money >= 150 && to->construct.is_click == 1 &&
        dwd->mouse.mouse_pos.x > spos.x + 160 && dwd->mouse.mouse_pos.x <
        spos.x + 242 && dwd->mouse.mouse_pos.y > spos.y + 158 &&
        dwd->mouse.mouse_pos.y < spos.y + 226) {
        to->construct.is_bought = check_pos(to, 13, spos);
        to->construct.rect_tower.left = 0;
        to->construct.rect_tower.top = 1005;
        to->construct.rect_tower.height = 257;
        to->construct.rect_tower.width = 202;
        to->construct.pos_tower.x = spos.x + 30;
        to->construct.pos_tower.y = spos.y - 65;
        sfSprite_setTextureRect(to->construct.towers_s[to->construct.is_bought],
                                to->construct.rect_tower);
        sfSprite_setPosition(to->construct.towers_s[to->construct.is_bought],
                            to->construct.pos_tower);
        to->construct.money -= 150;
        to->construct.is_click = 0;
        dwd->event.type = 0;
    }
}
