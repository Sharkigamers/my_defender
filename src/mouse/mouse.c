/*
** EPITECH PROJECT, 2019
** defender
** File description:
** mouse
*/

#include "my.h"

void ini_mouse(dwd_t *dwd)
{
    sfVector2f origin_mouse = {7, 13};
    sfVector2f sec_origin_mouse = {34, 30};

    dwd->mouse.which_mouse = 1;
    dwd->mouse.mouse_s = create_sprite
        ("assets/mouse/cursor.png", 0, 0);
    dwd->mouse.sec_mouse_s = create_sprite
        ("assets/mouse/cursor2.png", 0, 0);
    dwd->option.select_fmouse_s = create_sprite
        ("assets/mouse/cursor.png", 800, 700);
    dwd->option.select_smouse_s = create_sprite
        ("assets/mouse/cursor2.png", 1050, 700);
    sfRenderWindow_setMouseCursorVisible(dwd->window, sfFalse);
    sfSprite_setOrigin(dwd->mouse.mouse_s, origin_mouse);
    sfSprite_setOrigin(dwd->mouse.sec_mouse_s, sec_origin_mouse);
}

void mouse(dwd_t *dwd)
{
    dwd->mouse.mouse_pos = sfMouse_getPositionRenderWindow(dwd->window);
    dwd->mouse.pos.x = dwd->mouse.mouse_pos.x;
    dwd->mouse.pos.y = dwd->mouse.mouse_pos.y;
    if (dwd->mouse.which_mouse == 1) {
        sfSprite_setPosition(dwd->mouse.mouse_s, dwd->mouse.pos);
        sfRenderWindow_drawSprite(dwd->window, dwd->mouse.mouse_s, NULL);
    } else {
        sfSprite_setPosition(dwd->mouse.sec_mouse_s, dwd->mouse.pos);
        sfRenderWindow_drawSprite(dwd->window, dwd->mouse.sec_mouse_s, NULL);
    }
}
