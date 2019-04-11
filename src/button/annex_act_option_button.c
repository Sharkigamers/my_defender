/*
** EPITECH PROJECT, 2019
** defender
** File description:
** annex for acting button
*/

#include "my.h"

void cond_cursor(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 804 && dwd->mouse.mouse_pos.x < 866 &&
        dwd->mouse.mouse_pos.y > 709 && dwd->mouse.mouse_pos.y < 764) {
        dwd->mouse.which_mouse = 1;
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 1045 && dwd->mouse.mouse_pos.x < 1117 &&
        dwd->mouse.mouse_pos.y > 696 && dwd->mouse.mouse_pos.y < 755) {
        dwd->mouse.which_mouse = 2;
        sfMusic_play(dwd->sound.click);
    }
}
