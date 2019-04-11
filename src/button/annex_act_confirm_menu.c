/*
** EPITECH PROJECT, 2019
** defender
** File description:
** annext for acting confirm menu
*/

#include "my.h"

static void action_menu(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 816 && dwd->mouse.mouse_pos.x < 1110 &&
        dwd->mouse.mouse_pos.y > 431 && dwd->mouse.mouse_pos.y < 542) {
        dwd->pause.rect_menu.left = 769;
        sfSprite_setTextureRect
            (dwd->pause.menu_s, dwd->pause.rect_menu);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 816 && dwd->mouse.mouse_pos.x < 1110 &&
        dwd->mouse.mouse_pos.y > 431 && dwd->mouse.mouse_pos.y < 542) {
        dwd->event.type = 0;
        dwd->is_open = 1;
        all_pause(dwd);
        sfMusic_play(dwd->sound.menu);
    }
}

void cond_confirm_pause_menu(dwd_t *dwd)
{
    if (dwd->mouse.mouse_pos.x > 816 && dwd->mouse.mouse_pos.x < 1110 &&
        dwd->mouse.mouse_pos.y > 431 && dwd->mouse.mouse_pos.y < 542) {
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
