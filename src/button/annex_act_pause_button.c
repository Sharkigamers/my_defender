/*
** EPITECH PROJECT, 2019
** defender
** File description:
** annex for acting pause buttons
*/

#include "my.h"

void annex_action_menu(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 815 && dwd->mouse.mouse_pos.x < 1110 &&
        dwd->mouse.mouse_pos.y > 662 && dwd->mouse.mouse_pos.y < 772) {
        dwd->pause.pos_menu.x = 803;
        dwd->pause.pos_menu.y = 420;
        dwd->mbutton.pos_leave.x = 780;
        dwd->mbutton.pos_leave.y = 630;
        dwd->mbutton.pos_return.x = 770;
        dwd->mbutton.pos_return.y = 230;
        sfSprite_setPosition(dwd->mbutton.leave_s, dwd->mbutton.pos_leave);
        sfSprite_setPosition(dwd->pause.menu_s, dwd->pause.pos_menu);
        sfSprite_setPosition(dwd->mbutton.return_s, dwd->mbutton.pos_return);
        dwd->is_open = -3;
        dwd->event.type = 0;
    }
}

static void action_menu(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 815 && dwd->mouse.mouse_pos.x < 1110 &&
        dwd->mouse.mouse_pos.y > 662 && dwd->mouse.mouse_pos.y < 772) {
        dwd->pause.rect_menu.left = 769;
        sfSprite_setTextureRect
            (dwd->pause.menu_s, dwd->pause.rect_menu);
        sfMusic_play(dwd->sound.click);
    }
    annex_action_menu(dwd);
}

void cond_pause_menu(dwd_t *dwd)
{
    if (dwd->mouse.mouse_pos.x > 815 && dwd->mouse.mouse_pos.x < 1110 &&
        dwd->mouse.mouse_pos.y > 662 && dwd->mouse.mouse_pos.y < 772) {
        dwd->pause.rect_menu.left = 389;
        sfSprite_setTextureRect
            (dwd->pause.menu_s, dwd->pause.rect_menu);
    } else {
        dwd->pause.rect_menu.left = 12;
        sfSprite_setTextureRect
            (dwd->pause.menu_s, dwd->pause.rect_menu);
    }
    action_menu(dwd);
}
