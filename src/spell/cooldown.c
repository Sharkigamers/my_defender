/*
** EPITECH PROJECT, 2019
** defender
** File description:
** cooldown
*/

#include "my.h"

void cond_ini_text_spell(mob_t *mob)
{
    sfText_setColor(mob->spell.spell1_t, sfBlack);
    sfText_setColor(mob->spell.spell2_t, sfBlack);
    sfText_setColor(mob->spell.spell3_t, sfBlack);
    sfText_setCharacterSize(mob->spell.spell1_t, 50);
    sfText_setCharacterSize(mob->spell.spell2_t, 50);
    sfText_setCharacterSize(mob->spell.spell3_t, 50);
}

void ini_text_spell(mob_t *mob)
{
    sfFont *font = sfFont_createFromFile("assets/text/Questrian 2.otf");
    sfVector2f pos;

    pos.x = 730;
    pos.y = 920;
    mob->spell.spell1_t = sfText_create();
    mob->spell.spell2_t = sfText_create();
    mob->spell.spell3_t = sfText_create();
    sfText_setFont(mob->spell.spell1_t, font);
    sfText_setFont(mob->spell.spell2_t, font);
    sfText_setFont(mob->spell.spell3_t, font);
    cond_ini_text_spell(mob);
    sfText_setPosition(mob->spell.spell1_t, pos);
    pos.x = 930;
    sfText_setPosition(mob->spell.spell2_t, pos);
    pos.x = 1130;
    sfText_setPosition(mob->spell.spell3_t, pos);
}

void cond_cooldown(mob_t *mob, dwd_t *dwd)
{
    if (mob->spell.is_click[4] == 0) {
        mob->spell.time[1] = sfClock_getElapsedTime(mob->spell.clock[1]);
        mob->spell.sec[1] = mob->spell.time[1].microseconds / 1000000.0;
        if (mob->spell.sec[1] > 80) {
            mob->spell.is_click[4] = 1;
            sfClock_restart(mob->spell.clock[1]);
        }
        sfText_setString(mob->spell.spell2_t, my_itoa(80 - mob->spell.sec[1]));
        sfRenderWindow_drawText(dwd->window, mob->spell.spell2_t, NULL);
    }
    if (mob->spell.is_click[5] == 0) {
        mob->spell.time[2] = sfClock_getElapsedTime(mob->spell.clock[2]);
        mob->spell.sec[2] = mob->spell.time[2].microseconds / 1000000.0;
        if (mob->spell.sec[2] > 50) {
            mob->spell.is_click[5] = 1;
            sfClock_restart(mob->spell.clock[2]);
        }
        sfText_setString(mob->spell.spell3_t, my_itoa(50 - mob->spell.sec[2]));
        sfRenderWindow_drawText(dwd->window, mob->spell.spell3_t, NULL);
    }
}

void cooldown(mob_t *mob, dwd_t *dwd)
{
    if (mob->spell.is_click[3] == 0) {
        mob->spell.time[0] = sfClock_getElapsedTime(mob->spell.clock[0]);
        mob->spell.sec[0] = mob->spell.time[0].microseconds / 1000000.0;
        if (mob->spell.sec[0] > 40) {
            mob->spell.is_click[3] = 1;
            sfClock_restart(mob->spell.clock[0]);
        }
        sfText_setString(mob->spell.spell1_t, my_itoa(40 - mob->spell.sec[0]));
        sfRenderWindow_drawText(dwd->window, mob->spell.spell1_t, NULL);
    }
    cond_cooldown(mob, dwd);
}
