/*
** EPITECH PROJECT, 2019
** defender
** File description:
** act_confirm_menu
*/

#include "my.h"

static void action_leave(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 783 && dwd->mouse.mouse_pos.x < 1146 &&
        dwd->mouse.mouse_pos.y > 638 && dwd->mouse.mouse_pos.y < 776) {
        dwd->mbutton.rect_leave.left = 784;
        sfSprite_setTextureRect
            (dwd->mbutton.leave_s, dwd->mbutton.rect_leave);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 783 && dwd->mouse.mouse_pos.x < 1146 &&
        dwd->mouse.mouse_pos.y > 638 && dwd->mouse.mouse_pos.y < 776) {
        dwd->is_open = 0;
        sfRenderWindow_close(dwd->window);
    }
}

void cond_confirm_leave(dwd_t *dwd)
{
    if (dwd->mouse.mouse_pos.x > 783 && dwd->mouse.mouse_pos.x < 1146 &&
        dwd->mouse.mouse_pos.y > 638 && dwd->mouse.mouse_pos.y < 776) {
        dwd->mbutton.rect_leave.left = 397;
        sfSprite_setTextureRect
            (dwd->mbutton.leave_s, dwd->mbutton.rect_leave);
    } else {
        dwd->mbutton.rect_leave.left = 10;
        sfSprite_setTextureRect
            (dwd->mbutton.leave_s, dwd->mbutton.rect_leave);
    }
    action_leave(dwd);
}

static void annex_cond_return(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 782 && dwd->mouse.mouse_pos.x < 1149 &&
        dwd->mouse.mouse_pos.y > 231 && dwd->mouse.mouse_pos.y < 369) {
        dwd->event.type = 0;
        dwd->is_open = -2;
        dwd->mbutton.pos_leave.x = 745;
        dwd->mbutton.pos_leave.y = 815;
        dwd->pause.pos_menu.x = 803;
        dwd->pause.pos_menu.y = 650;
        dwd->mbutton.pos_return.x = 1500;
        dwd->mbutton.pos_return.y = 850;
        sfSprite_setPosition(dwd->mbutton.leave_s, dwd->mbutton.pos_leave);
        sfSprite_setPosition(dwd->mbutton.return_s, dwd->mbutton.pos_return);
        sfSprite_setPosition(dwd->pause.menu_s, dwd->pause.pos_menu);
    }
}

static void action_return(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 782 && dwd->mouse.mouse_pos.x < 1149 &&
        dwd->mouse.mouse_pos.y > 231 && dwd->mouse.mouse_pos.y < 369) {
        dwd->mbutton.rect_return.left = 776;
        sfSprite_setTextureRect
            (dwd->mbutton.return_s, dwd->mbutton.rect_return);
        sfMusic_play(dwd->sound.click);
    }
    annex_cond_return(dwd);
}

void cond_confirm_return(dwd_t *dwd)
{
    if (dwd->mouse.mouse_pos.x > 782 && dwd->mouse.mouse_pos.x < 1149 &&
        dwd->mouse.mouse_pos.y > 231 && dwd->mouse.mouse_pos.y < 369) {
        dwd->mbutton.rect_return.left = 388;
        sfSprite_setTextureRect
            (dwd->mbutton.return_s, dwd->mbutton.rect_return);
    } else {
        dwd->mbutton.rect_return.left = 1;
        sfSprite_setTextureRect
            (dwd->mbutton.return_s, dwd->mbutton.rect_return);
    }
    action_return(dwd);
}
