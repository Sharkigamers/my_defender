/*
** EPITECH PROJECT, 2019
** defender
** File description:
** confirm_menu
*/

#include "my.h"

void disp_confirm_menu(dwd_t *dwd)
{
    disp_bck_pause(dwd);
    sfRenderWindow_drawSprite(dwd->window, dwd->pause.pause_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->pause.menu_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->mbutton.return_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->mbutton.leave_s, NULL);
}

void confirm_menu(dwd_t *dwd)
{
    while (dwd->is_open == -3) {
        disp_confirm_menu(dwd);
        mouse(dwd);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event))
            event_in_menu(dwd);
        sfRenderWindow_display(dwd->window);
        cond_confirm_leave(dwd);
        cond_confirm_return(dwd);
        cond_confirm_pause_menu(dwd);
    }
}
