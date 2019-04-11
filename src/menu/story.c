/*
** EPITECH PROJECT, 2019
** defender
** File description:
** story
*/

#include "my.h"

void disp_story(dwd_t *dwd)
{
    sfRenderWindow_drawSprite(dwd->window, dwd->story.story_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->mbutton.return_s, NULL);
}

void show_story(dwd_t *dwd)
{
    while (dwd->is_open == 5) {
        disp_story(dwd);
        mouse(dwd);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event))
            event_in_menu(dwd);
        sfRenderWindow_display(dwd->window);
        if (cond_return(dwd) == 1)
            dwd->is_open = 1;
    }
}
