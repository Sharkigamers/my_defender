/*
** EPITECH PROJECT, 2019
** defender
** File description:
** option from pause
*/

#include "my.h"

void disp_pause_option(dwd_t *dwd)
{
    disp_bck_pause(dwd);
    sfRenderWindow_drawSprite(dwd->window, dwd->option.board_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->option.music_button_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->option.music_bar_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->option.select_fmouse_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->option.select_smouse_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->mbutton.return_s, NULL);
}

void show_pause_option(dwd_t *dwd)
{
    while (dwd->is_open == -1) {
        disp_pause_option(dwd);
        mouse(dwd);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event))
            event_in_menu(dwd);
        sfRenderWindow_display(dwd->window);
        cond_cursor(dwd);
        option_volume_sound(dwd);
        if (cond_return(dwd) == 1)
            dwd->is_open = -2;
    }
}
