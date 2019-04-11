/*
** EPITECH PROJECT, 2019
** defender
** File description:
** annex for acting button
*/

#include "my.h"

void action_story(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 740 && dwd->mouse.mouse_pos.x < 1120 &&
        dwd->mouse.mouse_pos.y > 610 && dwd->mouse.mouse_pos.y < 745) {
        dwd->mbutton.rect_story.left = 1269;
        sfSprite_setTextureRect
            (dwd->mbutton.story_s, dwd->mbutton.rect_story);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 740 && dwd->mouse.mouse_pos.x < 1120 &&
        dwd->mouse.mouse_pos.y > 610 && dwd->mouse.mouse_pos.y < 745)
        dwd->is_open = 5;
}

void cond_story(dwd_t *dwd)
{
    if (dwd->mouse.mouse_pos.x > 740 && dwd->mouse.mouse_pos.x < 1120 &&
        dwd->mouse.mouse_pos.y > 610 && dwd->mouse.mouse_pos.y < 745) {
        dwd->mbutton.rect_story.left = 640;
        sfSprite_setTextureRect
            (dwd->mbutton.story_s, dwd->mbutton.rect_story);
    } else {
        dwd->mbutton.rect_story.left = 11;
        sfSprite_setTextureRect
            (dwd->mbutton.story_s, dwd->mbutton.rect_story);
    }
    action_story(dwd);
}

static void action_leave(dwd_t *dwd)
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
