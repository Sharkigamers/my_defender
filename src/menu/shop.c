/*
** EPITECH PROJECT, 2019
** defender
** File description:
** shop
*/

#include "my.h"

void disp_shop(dwd_t *dwd)
{
    sfRenderWindow_drawSprite(dwd->window, dwd->shop.shop_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->mbutton.return_s, NULL);
}

void show_shop(dwd_t *dwd)
{
    while (dwd->is_open == 4) {
        disp_shop(dwd);
        mouse(dwd);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event))
            event_in_menu(dwd);
        sfRenderWindow_display(dwd->window);
        if (cond_return(dwd) == 1)
            dwd->is_open = 1;
    }
}
