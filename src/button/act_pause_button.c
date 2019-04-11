/*
** EPITECH PROJECT, 2019
** defender
** File description:
** act for button in pause
*/

#include "my.h"

void action_resume(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 815 && dwd->mouse.mouse_pos.x < 1110 &&
        dwd->mouse.mouse_pos.y > 228 && dwd->mouse.mouse_pos.y < 333) {
        dwd->pause.rect_resume.left = 769;
        sfSprite_setTextureRect
            (dwd->pause.resume_s, dwd->pause.rect_resume);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 815 && dwd->mouse.mouse_pos.x < 1110 &&
        dwd->mouse.mouse_pos.y > 228 && dwd->mouse.mouse_pos.y < 333) {
        dwd->is_open = dwd->pause.pause;
        dwd->event.type = 0;
    }
}

void cond_resume(dwd_t *dwd)
{
    if (dwd->mouse.mouse_pos.x > 815 && dwd->mouse.mouse_pos.x < 1110 &&
        dwd->mouse.mouse_pos.y > 228 && dwd->mouse.mouse_pos.y < 333) {
        dwd->pause.rect_resume.left = 389;
        sfSprite_setTextureRect
            (dwd->pause.resume_s, dwd->pause.rect_resume);
    } else {
        dwd->pause.rect_resume.left = 12;
        sfSprite_setTextureRect
            (dwd->pause.resume_s, dwd->pause.rect_resume);
    }
    action_resume(dwd);
}

static void action_option(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 796 && dwd->mouse.mouse_pos.x < 1129 &&
        dwd->mouse.mouse_pos.y > 363 && dwd->mouse.mouse_pos.y < 493) {
        dwd->mbutton.rect_option.left = 767;
        sfSprite_setTextureRect
            (dwd->mbutton.option_s, dwd->mbutton.rect_option);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 796 && dwd->mouse.mouse_pos.x < 1129 &&
        dwd->mouse.mouse_pos.y > 363 && dwd->mouse.mouse_pos.y < 493) {
        dwd->is_open = -1;
        dwd->event.type = 0;
    }
}

void cond_pause_option(dwd_t *dwd)
{
    if (dwd->mouse.mouse_pos.x > 796 && dwd->mouse.mouse_pos.x < 1129 &&
        dwd->mouse.mouse_pos.y > 363 && dwd->mouse.mouse_pos.y < 493) {
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
