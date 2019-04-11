/*
** EPITECH PROJECT, 2019
** defender
** File description:
** end_menu
*/

#include "my.h"

void inu_end_menu(dwd_t *dwd)
{
    dwd->end.victory = create_sprite("assets/menu/victory.jpg", 0, 0);
    dwd->end.defeate = create_sprite("assets/menu/defeate.jpg", 0, 0);
    dwd->end.is_reini = 0;
}

void disp_bck(dwd_t *dwd)
{
    switch (dwd->is_open) {
    case 18:
        sfRenderWindow_drawSprite(dwd->window, dwd->end.victory, NULL);
        break;
    case 19:
        sfRenderWindow_drawSprite(dwd->window, dwd->end.defeate, NULL);
        break;
    }
}

void end_menu(dwd_t *dwd)
{
    if (dwd->end.is_reini == 1) {
        dwd->pause.pos_menu.x = 803;
        dwd->pause.pos_menu.y = 420;
        sfSprite_setPosition(dwd->pause.menu_s, dwd->pause.pos_menu);
    }
    while (dwd->is_open == 18 || dwd->is_open == 19) {
        disp_bck(dwd);
        sfRenderWindow_drawSprite(dwd->window, dwd->pause.menu_s, NULL);
        mouse(dwd);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event))
            event_in_menu(dwd);
        sfRenderWindow_display(dwd->window);
        cond_confirm_pause_menu(dwd);
        dwd->end.is_reini = 0;
    }
}
