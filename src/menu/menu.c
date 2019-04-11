/*
** EPITECH PROJECT, 2019
** defender
** File description:
** menu
*/

#include "my.h"

void ini_menu(dwd_t *dwd)
{
    sfVector2f scl = {1, 0.95};
    sfVector2f scl2 = {2, 1.8};

    dwd->menu_s = create_sprite("assets/menu/menu1.jpg", 0, -460);
    sfSprite_setScale(dwd->menu_s, scl2);
    dwd->clock = sfClock_create();
    dwd->pbck.forest_s = create_sprite("assets/map/forest.jpg", 0, 0);
    sfSprite_setScale(dwd->pbck.forest_s, scl);
    dwd->pbck.desert_s = create_sprite("assets/map/desert.jpg", 0, 0);
    sfSprite_setScale(dwd->pbck.forest_s, scl);
    dwd->pbck.mountain_s = create_sprite("assets/map/mountain.jpg", 0, 0);
    sfSprite_setScale(dwd->pbck.forest_s, scl);
    dwd->pbck.hell_s = create_sprite("assets/map/hell.jpg", 0, 0);
    sfSprite_setScale(dwd->pbck.forest_s, scl);
    dwd->shop.shop_s = create_sprite("assets/menu/shop.jpg", 0, 0);
    dwd->story.story_s = create_sprite("assets/menu/story_bck1.jpg", 0, 0);
    dwd->option.board_s = create_sprite
        ("assets/menu/option_board.png", 510, 90);
    play_menu_song(dwd);
}

void disp_menu(dwd_t *dwd)
{
    sfRenderWindow_drawSprite(dwd->window, dwd->menu_s, NULL);
    anime_menu(dwd);
    sfRenderWindow_drawSprite(dwd->window, dwd->mbutton.play_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->mbutton.shop_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->mbutton.story_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->mbutton.leave_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->mbutton.option_s, NULL);
}

void event_in_menu(dwd_t *dwd)
{
    if (dwd->event.type == sfEvtClosed) {
        dwd->is_open = 0;
        sfRenderWindow_close(dwd->window);
    }
}

void show_menu(dwd_t *dwd, to_t *to, mob_t *mob)
{
    reini_before_menu(dwd, to, mob);
    while (dwd->is_open == 1) {
        disp_menu(dwd);
        mouse(dwd);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event))
            event_in_menu(dwd);
        sfRenderWindow_display(dwd->window);
        cond_menu(dwd, to);
    }
}
