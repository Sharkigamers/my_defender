/*
** EPITECH PROJECT, 2019
** defender
** File description:
** acting return button
*/

#include "my.h"

static int action_return(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 1505 && dwd->mouse.mouse_pos.x < 1868 &&
        dwd->mouse.mouse_pos.y > 855 && dwd->mouse.mouse_pos.y < 992) {
        dwd->mbutton.rect_return.left = 776;
        sfSprite_setTextureRect
            (dwd->mbutton.return_s, dwd->mbutton.rect_return);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 1505 && dwd->mouse.mouse_pos.x < 1868 &&
        dwd->mouse.mouse_pos.y > 855 && dwd->mouse.mouse_pos.y < 992) {
        dwd->event.type = 0;
        return (1);
    }
    return (0);
}

int cond_return(dwd_t *dwd)
{
    if (dwd->mouse.mouse_pos.x > 1505 && dwd->mouse.mouse_pos.x < 1868 &&
        dwd->mouse.mouse_pos.y > 855 && dwd->mouse.mouse_pos.y < 992) {
        dwd->mbutton.rect_return.left = 388;
        sfSprite_setTextureRect
            (dwd->mbutton.return_s, dwd->mbutton.rect_return);
    } else {
        dwd->mbutton.rect_return.left = 1;
        sfSprite_setTextureRect
            (dwd->mbutton.return_s, dwd->mbutton.rect_return);
    }
    if (action_return(dwd) == 1)
        return (1);
    return (0);
}

static void action_option(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 1500 && dwd->mouse.mouse_pos.x < 1835 &&
        dwd->mouse.mouse_pos.y > 840 && dwd->mouse.mouse_pos.y < 975) {
        dwd->mbutton.rect_option.left = 767;
        sfSprite_setTextureRect
            (dwd->mbutton.option_s, dwd->mbutton.rect_option);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 1500 && dwd->mouse.mouse_pos.x < 1835 &&
        dwd->mouse.mouse_pos.y > 840 && dwd->mouse.mouse_pos.y < 975) {
        dwd->is_open = -1;
        dwd->event.type = 0;
    }
}

void cond_option(dwd_t *dwd)
{
    if (dwd->mouse.mouse_pos.x > 1500 && dwd->mouse.mouse_pos.x < 1835 &&
        dwd->mouse.mouse_pos.y > 840 && dwd->mouse.mouse_pos.y < 975) {
        dwd->mbutton.rect_option.left = 384;
        sfSprite_setTextureRect
            (dwd->mbutton.option_s, dwd->mbutton.rect_option);
    } else {
        dwd->mbutton.rect_option.left = 10;
        sfSprite_setTextureRect
            (dwd->mbutton.option_s, dwd->mbutton.rect_option);
    }
    action_option(dwd);
}
