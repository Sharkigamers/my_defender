/*
** EPITECH PROJECT, 2019
** defender
** File description:
** pause
*/

#include "my.h"

void disp_bck_pause(dwd_t *dwd)
{
    switch (dwd->pause.pause) {
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

void disp_pause(dwd_t *dwd)
{
    disp_bck_pause(dwd);
    sfRenderWindow_drawSprite(dwd->window, dwd->pause.pause_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->pause.resume_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->mbutton.option_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->pause.music_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->pause.menu_s, NULL);
}

void event_in_pause(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtClosed) {
        dwd->is_open = 0;
        sfRenderWindow_close(dwd->window);
    }
    if (dwd->event.type == sfEvtKeyReleased &&
        dwd->event.key.code == sfKeyEscape) {
        dwd->is_open = dwd->pause.pause;
    }
}

void show_pause(dwd_t *dwd)
{
    while (dwd->is_open == -2) {
        disp_pause(dwd);
        mouse(dwd);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event))
            event_in_pause(dwd);
        sfRenderWindow_display(dwd->window);
        cond_resume(dwd);
        cond_pause_option(dwd);
        cond_pause_menu(dwd);
        cond_music(dwd);
        show_pause_option(dwd);
        confirm_menu(dwd);
    }
}
