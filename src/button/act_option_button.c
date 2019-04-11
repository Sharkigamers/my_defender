/*
** EPITECH PROJECT, 2019
** defender
** File description:
** action for music_button buttons
*/

#include "my.h"

void show_more_level_volume(dwd_t *dwd)
{
    switch (dwd->option.volume) {
    case 50:
        dwd->option.rect_music_bar.left = 1846;
        break;
    case 60:
        dwd->option.rect_music_bar.left = 2215;
        break;
    case 70:
        dwd->option.rect_music_bar.left = 2593;
        break;
    case 80:
        dwd->option.rect_music_bar.left = 2965;
        break;
    case 90:
        dwd->option.rect_music_bar.left = 3350;
        break;
    case 100:
        dwd->option.rect_music_bar.left = 3725;
        break;
    }
}

void show_level_volume(dwd_t *dwd)
{
    switch (dwd->option.volume) {
    case 0:
        dwd->option.rect_music_bar.left = 0;
        break;
    case 10:
        dwd->option.rect_music_bar.left = 370;
        break;
    case 20:
        dwd->option.rect_music_bar.left = 733;
        break;
    case 30:
        dwd->option.rect_music_bar.left = 1102;
        break;
    case 40:
        dwd->option.rect_music_bar.left = 1476;
        break;
    }
    show_more_level_volume(dwd);
}

void reaction_music_button(dwd_t *dwd, sfMusic *music)
{
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x >= 954 && dwd->mouse.mouse_pos.x < 1170 &&
        dwd->mouse.mouse_pos.y > 437 && dwd->mouse.mouse_pos.y < 525) {
        dwd->option.volume += 10;
        sfMusic_pause(music);
        sfMusic_setVolume(music, dwd->option.volume);
        sfMusic_play(music);
        dwd->event.type = 0;
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > 767 && dwd->mouse.mouse_pos.x < 954 &&
        dwd->mouse.mouse_pos.y > 437 && dwd->mouse.mouse_pos.y < 525) {
        dwd->option.volume -= 10;
        sfMusic_pause(music);
        sfMusic_setVolume(music, dwd->option.volume);
        sfMusic_play(music);
        dwd->event.type = 0;
    }
}

void action_music_button(dwd_t *dwd, sfMusic *music)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 954 && dwd->mouse.mouse_pos.x < 1133 &&
        dwd->mouse.mouse_pos.y > 437 && dwd->mouse.mouse_pos.y < 525) {
        dwd->option.rect_music_button.left = 513;
        sfSprite_setTextureRect
            (dwd->option.music_button_s, dwd->option.rect_music_button);
        sfMusic_play(dwd->sound.click);
    }
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > 767 && dwd->mouse.mouse_pos.x < 954 &&
        dwd->mouse.mouse_pos.y > 437 && dwd->mouse.mouse_pos.y < 525) {
        dwd->option.rect_music_button.left = 1017;
        sfSprite_setTextureRect
            (dwd->option.music_button_s, dwd->option.rect_music_button);
        sfMusic_play(dwd->sound.click);
    }
    reaction_music_button(dwd, music);
}

void cond_music_button(dwd_t *dwd, sfMusic *music)
{
    if ((dwd->mouse.mouse_pos.x < 767 || dwd->mouse.mouse_pos.x > 1133) ||
        (dwd->mouse.mouse_pos.y < 437 || dwd->mouse.mouse_pos.y > 525) ||
        dwd->event.type == sfEvtMouseButtonReleased) {
        dwd->option.rect_music_button.left = 10;
        sfSprite_setTextureRect
            (dwd->option.music_button_s, dwd->option.rect_music_button);
    }
    action_music_button(dwd, music);
    dwd->option.volume < 0 ? dwd->option.volume = 0 : 0;
    dwd->option.volume > 100 ? dwd->option.volume = 100 : 0;
    show_level_volume(dwd);
    sfSprite_setTextureRect
            (dwd->option.music_bar_s, dwd->option.rect_music_bar);
}
