/*
** EPITECH PROJECT, 2019
** defender
** File description:
** act_button
*/

#include "my.h"

void action_play(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 740 && dwd->mouse.mouse_pos.x < 1118 &&
        dwd->mouse.mouse_pos.y > 102 && dwd->mouse.mouse_pos.y < 250) {
        dwd->mbutton.rect_play.left = 923;
        sfSprite_setTextureRect
            (dwd->mbutton.play_s, dwd->mbutton.rect_play);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 740 && dwd->mouse.mouse_pos.x < 1118 &&
        dwd->mouse.mouse_pos.y > 102 && dwd->mouse.mouse_pos.y < 250) {
        dwd->is_open = 2;
        dwd->event.type = 0;
    }
}

void cond_play(dwd_t *dwd)
{
    if (dwd->mouse.mouse_pos.x > 740 && dwd->mouse.mouse_pos.x < 1118 &&
        dwd->mouse.mouse_pos.y > 102 && dwd->mouse.mouse_pos.y < 250) {
        dwd->mbutton.rect_play.left = 467;
        sfSprite_setTextureRect
            (dwd->mbutton.play_s, dwd->mbutton.rect_play);
    } else {
        dwd->mbutton.rect_play.left = 11;
        sfSprite_setTextureRect
            (dwd->mbutton.play_s, dwd->mbutton.rect_play);
    }
    action_play(dwd);
}

void action_shop(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 750 && dwd->mouse.mouse_pos.x < 1110 &&
        dwd->mouse.mouse_pos.y > 355 && dwd->mouse.mouse_pos.y < 485) {
        dwd->mbutton.rect_shop.left = 799;
        sfSprite_setTextureRect
            (dwd->mbutton.shop_s, dwd->mbutton.rect_shop);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 750 && dwd->mouse.mouse_pos.x < 1110 &&
        dwd->mouse.mouse_pos.y > 355 && dwd->mouse.mouse_pos.y < 485)
        dwd->is_open = 4;
}

void cond_shop(dwd_t *dwd)
{
    if (dwd->mouse.mouse_pos.x > 750 && dwd->mouse.mouse_pos.x < 1110 &&
        dwd->mouse.mouse_pos.y > 355 && dwd->mouse.mouse_pos.y < 485) {
        dwd->mbutton.rect_shop.left = 405;
        sfSprite_setTextureRect
            (dwd->mbutton.shop_s, dwd->mbutton.rect_shop);
    } else {
        dwd->mbutton.rect_shop.left = 11;
        sfSprite_setTextureRect
            (dwd->mbutton.shop_s, dwd->mbutton.rect_shop);
    }
    action_shop(dwd);
}
