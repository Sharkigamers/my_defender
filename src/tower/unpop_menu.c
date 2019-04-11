/*
** EPITECH PROJECT, 2019
** defender
** File description:
** open menu of upgrade and constructor
*/

#include "my.h"

void unpop_menu(to_t *to, dwd_t *dwd)
{
    sfVector2f get_pos = sfSprite_getPosition(to->construct.construct_s);
    sfVector2f get_spos = sfSprite_getPosition(to->construct.upgrade_s);

    if (dwd->event.type == sfEvtMouseButtonPressed &&
        to->construct.is_click == 1 &&
        (dwd->mouse.mouse_pos.x < get_pos.x ||
         dwd->mouse.mouse_pos.x > get_pos.x + 260 ||
         dwd->mouse.mouse_pos.y < get_pos.y ||
         dwd->mouse.mouse_pos.y > get_pos.y + 250))
        to->construct.is_click = 0;
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        (to->construct.is_click == 2 || to->construct.is_click == 3) &&
        (dwd->mouse.mouse_pos.x < get_spos.x ||
         dwd->mouse.mouse_pos.x > get_spos.x + 244 ||
         dwd->mouse.mouse_pos.y < get_spos.y ||
         dwd->mouse.mouse_pos.y > get_spos.y + 252))
        to->construct.is_click = 0;
}
