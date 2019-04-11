/*
** EPITECH PROJECT, 2019
** defender
** File description:
** act of buttons
*/

#include "my.h"

void action_easy(dwd_t *dwd, to_t *to)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 755 && dwd->mouse.mouse_pos.x < 1130 &&
        dwd->mouse.mouse_pos.y > 50 && dwd->mouse.mouse_pos.y < 216) {
        dwd->pbutton.rect_easy.left = 942;
        sfSprite_setTextureRect
            (dwd->pbutton.easy_s, dwd->pbutton.rect_easy);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 755 && dwd->mouse.mouse_pos.x < 1130 &&
        dwd->mouse.mouse_pos.y > 50 && dwd->mouse.mouse_pos.y < 216) {
        dwd->is_open = 10;
        special_memset(to, 6);
        to->construct.money = 500;
        sfMusic_stop(dwd->sound.menu);
    }
}

void cond_easy(dwd_t *dwd, to_t *to)
{
    if (dwd->mouse.mouse_pos.x > 755 && dwd->mouse.mouse_pos.x < 1130 &&
        dwd->mouse.mouse_pos.y > 50 && dwd->mouse.mouse_pos.y < 216) {
        dwd->pbutton.rect_easy.left = 473;
        sfSprite_setTextureRect
            (dwd->pbutton.easy_s, dwd->pbutton.rect_easy);
        dwd->pbutton.change_bck = 1;
    } else {
        dwd->pbutton.rect_easy.left = 4;
        sfSprite_setTextureRect
            (dwd->pbutton.easy_s, dwd->pbutton.rect_easy);
    }
    action_easy(dwd, to);
}

void action_medium(dwd_t *dwd, to_t *to)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 770 && dwd->mouse.mouse_pos.x < 1120 &&
        dwd->mouse.mouse_pos.y > 298 && dwd->mouse.mouse_pos.y < 460) {
        dwd->pbutton.rect_medium.left = 909;
        sfSprite_setTextureRect
            (dwd->pbutton.medium_s, dwd->pbutton.rect_medium);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 770 && dwd->mouse.mouse_pos.x < 1120 &&
        dwd->mouse.mouse_pos.y > 298 && dwd->mouse.mouse_pos.y < 460) {
        dwd->is_open = 11;
        to->construct.money = 220;
        sfMusic_stop(dwd->sound.menu);
    }
}

void cond_medium(dwd_t *dwd, to_t *to)
{
    if (dwd->mouse.mouse_pos.x > 770 && dwd->mouse.mouse_pos.x < 1120 &&
        dwd->mouse.mouse_pos.y > 298 && dwd->mouse.mouse_pos.y < 460) {
        dwd->pbutton.rect_medium.left = 456;
        sfSprite_setTextureRect
            (dwd->pbutton.medium_s, dwd->pbutton.rect_medium);
        dwd->pbutton.change_bck = 2;
    } else {
        dwd->pbutton.rect_medium.left = 4;
        sfSprite_setTextureRect
            (dwd->pbutton.medium_s, dwd->pbutton.rect_medium);
    }
    action_medium(dwd, to);
}

int deal_money(int i, to_t *to)
{
    to->construct.money = to->construct.money + i;
    return (0);
}
