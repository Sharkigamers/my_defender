/*
** EPITECH PROJECT, 2019
** defender
** File description:
** gameplay
*/

#include "my.h"

void disp_game(dwd_t *dwd)
{
    switch (dwd->is_open) {
    case 10:
        sfRenderWindow_drawSprite(dwd->window, dwd->pbck.forest_s, NULL);
        break;
    case 11:
        sfRenderWindow_drawSprite(dwd->window, dwd->pbck.desert_s, NULL);
        break;
    case 12:
        sfRenderWindow_drawSprite(dwd->window, dwd->pbck.mountain_s, NULL);
        break;
    case 13:
        sfRenderWindow_drawSprite(dwd->window, dwd->pbck.hell_s, NULL);
        break;
    }
}

void music_by_map(dwd_t *dwd)
{
    switch (dwd->is_open) {
    case 10:
        dwd->sound.wich_music = 1;
        break;
    case 11:
        dwd->sound.wich_music = 3;
        break;
    case 12:
        dwd->sound.wich_music = 5;
        break;
    case 13:
        dwd->sound.wich_music = 7;
        break;
    }
    chose_music(dwd);
}

void event_in_gameplay(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtClosed) {
        dwd->is_open = 0;
        sfRenderWindow_close(dwd->window);
    }
    if (dwd->event.type == sfEvtKeyReleased &&
        dwd->event.key.code == sfKeyEscape) {
        dwd->pause.pause = dwd->is_open;
        dwd->is_open = -2;
    }
}

void use_game_clock(dwd_t *dwd)
{
    dwd->cgame.time[0] = sfClock_getElapsedTime(dwd->cgame.clock[0]);
    dwd->cgame.sec[0] = dwd->cgame.time[0].microseconds / 1000000.0;
    dwd->cgame.time[1] = sfClock_getElapsedTime(dwd->cgame.clock[1]);
    dwd->cgame.sec[1] = dwd->cgame.time[1].microseconds / 1000000.0;
    dwd->cgame.time[2] = sfClock_getElapsedTime(dwd->cgame.clock[2]);
    dwd->cgame.sec[2] = dwd->cgame.time[2].microseconds / 1000000.0;
    dwd->cgame.time[3] = sfClock_getElapsedTime(dwd->cgame.clock[3]);
    dwd->cgame.sec[3] = dwd->cgame.time[3].microseconds / 1000000.0;
}

void main_game(dwd_t *dwd, mob_t *mob, to_t *to)
{
    dwd->mbutton.pos_option.x = 795;
    dwd->mbutton.pos_option.y = 360;
    sfSprite_setPosition(dwd->mbutton.option_s, dwd->mbutton.pos_option);
    music_by_map(dwd);
    while (dwd->is_open >= 10 && dwd->is_open <= 13) {
        disp_game(dwd);
        use_game_clock(dwd);
        sfRenderWindow_drawSprite(dwd->window, to->money_bar_s, NULL);
        print_redmob(dwd, mob);
        check_range(to, mob);
        show_construction(to, dwd);
        disp_spell(mob, dwd);
        check_hitbox(dwd, mob);
        annex_gameplay(dwd, mob, to);
    }
}
