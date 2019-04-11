/*
** EPITECH PROJECT, 2019
** defender
** File description:
** annex_ini_all
*/

#include "my.h"

void annex_reini_before_menu(mob_t *mob)
{
    for (int i = 0; i < 3; i++) {
        mob->life.rect_life[i].left = 0;
        mob->life.rect_life[i].top = 0;
        mob->life.rect_life[i].height = 150;
        mob->life.rect_life[i].width = 150;
        sfSprite_setTextureRect(mob->life.life_spr[i], mob->life.rect_life[i]);
    }
    for (int i = 3; i < 6; i++)
        mob->spell.is_click[i] = 1;
    mob->life.life = 3;
    annex_spell(mob);
}

void reini_before_menu(dwd_t *dwd, to_t *to, mob_t *mob)
{
    dwd->sound.wich_music = 0;
    dwd->mbutton.pos_option.x = 1500;
    dwd->mbutton.pos_option.y = 840;
    dwd->mbutton.pos_leave.x = 745;
    dwd->mbutton.pos_leave.y = 815;
    dwd->pause.pos_menu.x = 803;
    dwd->pause.pos_menu.y = 650;
    dwd->mbutton.pos_return.x = 1500;
    dwd->mbutton.pos_return.y = 850;
    to->construct.is_click = 0;
    to->money.upg_money = 0;
    sfSprite_setPosition(dwd->mbutton.option_s, dwd->mbutton.pos_option);
    sfSprite_setPosition(dwd->mbutton.leave_s, dwd->mbutton.pos_leave);
    sfSprite_setPosition(dwd->mbutton.return_s, dwd->mbutton.pos_return);
    sfSprite_setPosition(dwd->pause.menu_s, dwd->pause.pos_menu);
    annex_reini_before_menu(mob);
}

void ini_game_clock(dwd_t *dwd)
{
    dwd->cgame.clock = malloc(sizeof(sfClock *) * 5);
    dwd->cgame.time = malloc(sizeof(sfTime *) * 5);
    dwd->cgame.sec = malloc(sizeof(float *) * 5);
    dwd->cgame.clock[0] = sfClock_create();
    dwd->cgame.clock[1] = sfClock_create();
    dwd->cgame.clock[2] = sfClock_create();
    dwd->cgame.clock[3] = sfClock_create();
}

void first(dwd_t *dwd, to_t *to, sfIntRect *left)
{
    static int a = 0;

    if (a == 0) {
        to->money.upg_money = 0;
        dwd->is_open = 1;
        left->left = left->left + 600;
        sfSprite_setTextureRect(dwd->loading, *left);
        dwd->pbutton.change_bck = 0;
        to->construct.is_bought = 0;
        left->left = left->left + 600;
        sfSprite_setTextureRect(dwd->loading, *left);
        to->construct.is_click = 0;
        dwd->window = create_mywindow(1920, 1080);
        ini_menu(dwd);
        left->left = left->left + 600;
        sfSprite_setTextureRect(dwd->loading, *left);
        ini_button(dwd);
        a++;
    }
}
