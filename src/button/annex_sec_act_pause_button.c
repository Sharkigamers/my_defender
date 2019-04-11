/*
** EPITECH PROJECT, 2019
** defender
** File description:
** another acting for button from pause
*/

#include "my.h"

void release_music(dwd_t *dwd)
{

    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 817 && dwd->mouse.mouse_pos.x < 960 &&
        dwd->mouse.mouse_pos.y > 519 && dwd->mouse.mouse_pos.y < 630) {
        if ((dwd->sound.wich_music % 2) == 0) {
            dwd->sound.wich_music--;
            chose_music(dwd);
        }
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 960 && dwd->mouse.mouse_pos.x < 1109 &&
        dwd->mouse.mouse_pos.y > 519 && dwd->mouse.mouse_pos.y < 630) {
        if ((dwd->sound.wich_music % 2) == 1) {
            dwd->sound.wich_music++;
            chose_music(dwd);
        }
    }
}

void action_music(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 817 && dwd->mouse.mouse_pos.x < 960 &&
        dwd->mouse.mouse_pos.y > 519 && dwd->mouse.mouse_pos.y < 630) {
        dwd->pause.rect_music.left = 753;
        sfSprite_setTextureRect
            (dwd->pause.music_s, dwd->pause.rect_music);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 960 && dwd->mouse.mouse_pos.x < 1109 &&
        dwd->mouse.mouse_pos.y > 519 && dwd->mouse.mouse_pos.y < 630) {
        dwd->pause.rect_music.left = 1132;
        sfSprite_setTextureRect
            (dwd->pause.music_s, dwd->pause.rect_music);
        sfMusic_play(dwd->sound.click);
    }
}

void cond_music(dwd_t *dwd)
{
    if (dwd->mouse.mouse_pos.x > 817 && dwd->mouse.mouse_pos.x < 1109 &&
        dwd->mouse.mouse_pos.y > 519 && dwd->mouse.mouse_pos.y < 630) {
        dwd->pause.rect_music.left = 372;
        sfSprite_setTextureRect
            (dwd->pause.music_s, dwd->pause.rect_music);
    } else {
        dwd->pause.rect_music.left = 12;
        sfSprite_setTextureRect
            (dwd->pause.music_s, dwd->pause.rect_music);
    }
    action_music(dwd);
    release_music(dwd);
}
