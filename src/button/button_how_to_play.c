/*
** EPITECH PROJECT, 2019
** defender
** File description:
** how to play
*/

#include "my.h"

void action_htp(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 117 && dwd->mouse.mouse_pos.x < 414 &&
        dwd->mouse.mouse_pos.y > 824 && dwd->mouse.mouse_pos.y < 934) {
        dwd->pbutton.rect_htp.left = 718;
        sfSprite_setTextureRect
            (dwd->pbutton.htp_s, dwd->pbutton.rect_htp);
        sfMusic_play(dwd->sound.click);
        dwd->htp.rect_htp.left = 0;
        sfSprite_setTextureRect(dwd->htp.htp_s, dwd->htp.rect_htp);
        sfClock_restart(dwd->htp.clock);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 117 && dwd->mouse.mouse_pos.x < 414 &&
        dwd->mouse.mouse_pos.y > 824 && dwd->mouse.mouse_pos.y < 934) {
        dwd->is_open = 20;
        dwd->htp.sec = 0;
    }
}

void cond_htp(dwd_t *dwd)
{
    if (dwd->mouse.mouse_pos.x > 117 && dwd->mouse.mouse_pos.x < 414 &&
        dwd->mouse.mouse_pos.y > 824 && dwd->mouse.mouse_pos.y < 934) {
        dwd->pbutton.rect_htp.left = 362;
        sfSprite_setTextureRect
            (dwd->pbutton.htp_s, dwd->pbutton.rect_htp);
        dwd->pbutton.change_bck = 3;
    } else {
        dwd->pbutton.rect_htp.left = 4;
        sfSprite_setTextureRect
            (dwd->pbutton.htp_s, dwd->pbutton.rect_htp);
    }
    action_htp(dwd);
}
