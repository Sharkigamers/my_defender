/*
** EPITECH PROJECT, 2019
** defender
** File description:
** htp
*/

#include "my.h"

void ini_htp(dwd_t *dwd)
{
    sfVector2f scl;

    scl.x = 1.3;
    scl.y = 1.3;
    dwd->htp.htp_s = create_sprite("assets/menu/htp_menu.png", 100, 100);
    dwd->htp.rect_htp.left = 0;
    dwd->htp.rect_htp.top = 0;
    dwd->htp.rect_htp.height = 670;
    dwd->htp.rect_htp.width = 1010;
    sfSprite_setTextureRect(dwd->htp.htp_s, dwd->htp.rect_htp);
    sfSprite_setScale(dwd->htp.htp_s, scl);
    dwd->htp.clock = sfClock_create();
}

void clocked_htp(dwd_t *dwd)
{
    dwd->htp.time = sfClock_getElapsedTime(dwd->htp.clock);
    dwd->htp.sec = dwd->htp.time.microseconds / 1000000.0;
    if (dwd->htp.sec > 5) {
        dwd->htp.rect_htp.left += 1023;
        if (dwd->htp.rect_htp.left > 4010)
            dwd->htp.rect_htp.left = 0;
        sfSprite_setTextureRect(dwd->htp.htp_s, dwd->htp.rect_htp);
        sfClock_restart(dwd->htp.clock);
    }
}

void show_menu_htp(dwd_t *dwd)
{
    while (dwd->is_open == 20) {
        sfRenderWindow_drawSprite(dwd->window, dwd->menu_s, NULL);
        anime_menu(dwd);
        sfRenderWindow_drawSprite(dwd->window, dwd->htp.htp_s, NULL);
        sfRenderWindow_drawSprite(dwd->window, dwd->mbutton.return_s, NULL);
        mouse(dwd);
        clocked_htp(dwd);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event))
            event_in_menu(dwd);
        sfRenderWindow_display(dwd->window);
        if (cond_return(dwd) == 1)
            dwd->is_open = 2;
    }
}
