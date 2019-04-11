/*
** EPITECH PROJECT, 2019
** defender
** File description:
** annex_gameplay
*/

#include "my.h"

void annex_gameplay(dwd_t *dwd, mob_t *mob, to_t *to)
{
    for (int i = 0; i != 6; i++) {
        sfRenderWindow_drawSprite(dwd->window, to->project.arrow[i], NULL);
        sfRenderWindow_drawSprite(dwd->window, to->mage.spell[i], NULL);
        sfRenderWindow_drawSprite(dwd->window, to->moltar.rock[i], NULL);
    }
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(dwd->window, mob->life.life_spr[i], NULL);
    mouse(dwd);
    if (sfRenderWindow_pollEvent(dwd->window, &dwd->event))
        event_in_gameplay(dwd);
    if (mob->life.life <= 0) {
        dwd->is_open = 19;
        dwd->end.is_reini = 1;
    }
    sfRenderWindow_display(dwd->window);
    show_pause(dwd);
    end_menu(dwd);
}
