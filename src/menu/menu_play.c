/*
** EPITECH PROJECT, 2019
** defender
** File description:
** menu_play
*/

#include "my.h"

void cond_disp_bck(dwd_t *dwd)
{
    switch (dwd->pbutton.change_bck) {
    case 0:
        sfRenderWindow_drawSprite(dwd->window, dwd->menu_s, NULL);
        break;
    case 1:
        sfRenderWindow_drawSprite(dwd->window, dwd->pbck.forest_s, NULL);
        break;
    case 2:
        sfRenderWindow_drawSprite(dwd->window, dwd->pbck.desert_s, NULL);
        break;
    case 3:
        sfRenderWindow_drawSprite(dwd->window, dwd->pbck.mountain_s, NULL);
        break;
    case 4:
        sfRenderWindow_drawSprite(dwd->window, dwd->pbck.hell_s, NULL);
        break;
    }
    sfRenderWindow_drawSprite(dwd->window, dwd->pbutton.htp_s, NULL);
}

void disp_play_menu(dwd_t *dwd)
{
    if (((dwd->mouse.mouse_pos.x > 755 && dwd->mouse.mouse_pos.x < 1130) &&
         (dwd->mouse.mouse_pos.y > 50 && dwd->mouse.mouse_pos.y < 216)) ||
        ((dwd->mouse.mouse_pos.x > 770 && dwd->mouse.mouse_pos.x < 1120) &&
         (dwd->mouse.mouse_pos.y > 298 && dwd->mouse.mouse_pos.y < 460)) ||
        ((dwd->mouse.mouse_pos.x > 755 && dwd->mouse.mouse_pos.x < 1134) &&
         (dwd->mouse.mouse_pos.y > 562 && dwd->mouse.mouse_pos.y < 703)) ||
        ((dwd->mouse.mouse_pos.x > 735 && dwd->mouse.mouse_pos.x < 1145) &&
         (dwd->mouse.mouse_pos.y > 830 && dwd->mouse.mouse_pos.y < 989)));
    else
        dwd->pbutton.change_bck = 0;
    cond_disp_bck(dwd);
    sfRenderWindow_drawSprite(dwd->window, dwd->pbutton.easy_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->pbutton.medium_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->pbutton.hard_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->pbutton.hell_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->mbutton.return_s, NULL);
}

void show_menu_play(dwd_t *dwd, to_t *to)
{
    while (dwd->is_open == 2) {
        disp_play_menu(dwd);
        mouse(dwd);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event))
            event_in_menu(dwd);
        sfRenderWindow_display(dwd->window);
        anime_menu(dwd);
        cond_easy(dwd, to);
        cond_medium(dwd, to);
        cond_hard(dwd, to);
        cond_hell(dwd, to);
        cond_htp(dwd);
        show_menu_htp(dwd);
        if (cond_return(dwd) == 1)
            dwd->is_open = 1;
    }
}
