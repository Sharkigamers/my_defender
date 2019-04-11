/*
** EPITECH PROJECT, 2019
** defender
** File description:
** menu_from_button_pause
*/

#include "my.h"

static void action_menu_pause(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 815 && dwd->mouse.mouse_pos.x < 1110 &&
        dwd->mouse.mouse_pos.y > 662 && dwd->mouse.mouse_pos.y < 772) {
        dwd->pause.rect_menu.left = 769;
        sfSprite_setTextureRect
            (dwd->pause.menu_s, dwd->pause.rect_menu);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 815 && dwd->mouse.mouse_pos.x < 1110 &&
        dwd->mouse.mouse_pos.y > 662 && dwd->mouse.mouse_pos.y < 772) {
        dwd->is_open = 1;
        dwd->event.type = 0;
    }
}

void cond_pause_menu_pause(dwd_t *dwd)
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

void action_leave(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 750 && dwd->mouse.mouse_pos.x < 1117 &&
        dwd->mouse.mouse_pos.y > 820 && dwd->mouse.mouse_pos.y < 965) {
        dwd->mbutton.rect_leave.left = 784;
        sfSprite_setTextureRect
            (dwd->mbutton.leave_s, dwd->mbutton.rect_leave);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 750 && dwd->mouse.mouse_pos.x < 1117 &&
        dwd->mouse.mouse_pos.y > 820 && dwd->mouse.mouse_pos.y < 965) {
        dwd->is_open = 0;
        sfRenderWindow_close(dwd->window);
    }
}

void cond_leave(dwd_t *dwd)
{
    if (dwd->mouse.mouse_pos.x > 750 && dwd->mouse.mouse_pos.x < 1117 &&
        dwd->mouse.mouse_pos.y > 820 && dwd->mouse.mouse_pos.y < 965) {
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
