/*
** EPITECH PROJECT, 2019
** defender
** File description:
** annex for acting buttons
*/

#include "my.h"

void action_hard(dwd_t *dwd, to_t *to)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 755 && dwd->mouse.mouse_pos.x < 1134 &&
        dwd->mouse.mouse_pos.y > 562 && dwd->mouse.mouse_pos.y < 703) {
        dwd->pbutton.rect_hard.left = 966;
        sfSprite_setTextureRect
            (dwd->pbutton.hard_s, dwd->pbutton.rect_hard);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 755 && dwd->mouse.mouse_pos.x < 1134 &&
        dwd->mouse.mouse_pos.y > 562 && dwd->mouse.mouse_pos.y < 703) {
        dwd->is_open = 12;
        to->construct.money = 230;
        sfMusic_stop(dwd->sound.menu);
    }
}

void cond_hard(dwd_t *dwd, to_t *to)
{
    if (dwd->mouse.mouse_pos.x > 755 && dwd->mouse.mouse_pos.x < 1134 &&
        dwd->mouse.mouse_pos.y > 562 && dwd->mouse.mouse_pos.y < 703) {
        dwd->pbutton.rect_hard.left = 485;
        sfSprite_setTextureRect
            (dwd->pbutton.hard_s, dwd->pbutton.rect_hard);
        dwd->pbutton.change_bck = 3;
    } else {
        dwd->pbutton.rect_hard.left = 4;
        sfSprite_setTextureRect
            (dwd->pbutton.hard_s, dwd->pbutton.rect_hard);
    }
    action_hard(dwd, to);
}

void action_hell(dwd_t *dwd, to_t *to)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 735 && dwd->mouse.mouse_pos.x < 1145 &&
        dwd->mouse.mouse_pos.y > 830 && dwd->mouse.mouse_pos.y < 989) {
        dwd->pbutton.rect_hell.left = 966;
        sfSprite_setTextureRect
            (dwd->pbutton.hell_s, dwd->pbutton.rect_hell);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 735 && dwd->mouse.mouse_pos.x < 1145 &&
        dwd->mouse.mouse_pos.y > 830 && dwd->mouse.mouse_pos.y < 989) {
        dwd->is_open = 13;
        to->construct.money = 235;
        sfMusic_stop(dwd->sound.menu);
    }
}

void cond_hell(dwd_t *dwd, to_t *to)
{
    if (dwd->mouse.mouse_pos.x > 735 && dwd->mouse.mouse_pos.x < 1145 &&
        dwd->mouse.mouse_pos.y > 830 && dwd->mouse.mouse_pos.y < 989) {
        dwd->pbutton.rect_hell.left = 485;
        sfSprite_setTextureRect
            (dwd->pbutton.hell_s, dwd->pbutton.rect_hell);
        dwd->pbutton.change_bck = 4;
    } else {
        dwd->pbutton.rect_hell.left = 4;
        sfSprite_setTextureRect
            (dwd->pbutton.hell_s, dwd->pbutton.rect_hell);
    }
    action_hell(dwd, to);
}
