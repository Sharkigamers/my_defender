/*
** EPITECH PROJECT, 2019
** loading.c
** File description:
** create my loading
*/

#include "my.h"

sfRenderWindow *createload(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode vd_md = {width, height, 32};

    window = sfRenderWindow_create(vd_md, "LOADING",
                                    sfResize | sfClose, NULL);
    return (window);
}

void init_load(sfClock **clock, sfSprite **press, dwd_t *dwd)
{
    sfVector2f scl;

    *clock = sfClock_create();
    scl.x = 3.2;
    scl.y = 3.4;
    *press = create_sprite("./assets/menu/press.png", 0, 0);
    dwd->loading = create_sprite("./assets/menu/loading.png", 0, 0);
    sfSprite_setScale(*press, scl);
    sfSprite_setScale(dwd->loading, scl);
}

void loading_window(dwd_t *dwd, mob_t *mob, to_t *to)
{
    sfRenderWindow *window;
    static sfIntRect left = {0, 0, 600, 300};
    sfSprite *press;
    sfClock *clock;

    init_load(&clock, &press, dwd);
    window = createload(1920, 1080);
    while (sfRenderWindow_isOpen(window)) {
        first(dwd, to, &left);
        sfRenderWindow_drawSprite(window, dwd->loading, NULL);
        if (left.left >= 12600)
            sfRenderWindow_drawSprite(window, press, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyReturn))
            sfRenderWindow_close(window);
        sfRenderWindow_display(window);
        second(dwd, mob, to, &left);
        three(dwd, mob, to, &left);
    }
}
