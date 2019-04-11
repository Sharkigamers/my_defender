/*
** EPITECH PROJECT, 2019
** defender
** File description:
** init all
*/

#include "my.h"

void second(dwd_t *dwd, mob_t *mob, to_t *to, sfIntRect *left)
{
    static int a = 0;

    if (a == 0) {
        mob->green.nb_mob = 2;
        mob->black.nb_mob = 1;
        left->left = left->left + 600;
        sfSprite_setTextureRect(dwd->loading, *left);
        create_mymob_spr(mob);
        malloc_clock_tower(to);
        left->left = left->left + 600;
        sfSprite_setTextureRect(dwd->loading, *left);
        init_life_mob(mob);
        left->left = left->left + 600;
        sfSprite_setTextureRect(dwd->loading, *left);
        ini_game_clock(dwd);
        left->left = left->left + 600;
        sfSprite_setTextureRect(dwd->loading, *left);
        ini_building(to, 20);
        a++;
    }
}

void three(dwd_t *dwd, mob_t *mob, to_t *to, sfIntRect *left)
{
    static int a = 0;

    if (a == 0) {
        mob->red.nb_mob = 5;
        left->left = left->left + 600;
        sfSprite_setTextureRect(dwd->loading, *left);
        ini_constructor(to);
        ini_money(to);
        left->left = left->left + 600;
        sfSprite_setTextureRect(dwd->loading, *left);
        ini_life(mob);
        left->left = left->left + 600;
        sfSprite_setTextureRect(dwd->loading, *left);
        ini_mouse(dwd);
        left->left = 12600;
        sfSprite_setTextureRect(dwd->loading, *left);
        a++;
    }
}

void annex_ini_all(mob_t *mob)
{
    ini_spell(mob);
    ini_text_spell(mob);
}

void cond_ini_all(dwd_t *dwd, mob_t *mob, to_t *to)
{
    create_mymob_spr(mob);
    malloc_clock_tower(to);
    init_life_mob(mob);
    ini_game_clock(dwd);
    ini_building(to, 20);
    ini_constructor(to);
    ini_money(to);
    ini_life(mob);
    ini_mouse(dwd);
    annex_ini_all(mob);
    ini_htp(dwd);
    inu_end_menu(dwd);
}

void ini_all(dwd_t *dwd, mob_t *mob, to_t *to)
{
    to->money.upg_money = 0;
    dwd->is_open = 1;
    dwd->pbutton.change_bck = 0;
    to->construct.is_bought = 0;
    to->construct.is_click = 0;
    dwd->window = create_mywindow(1920, 1080);
    ini_menu(dwd);
    ini_button(dwd);
    mob->red.nb_mob = 3;
    mob->green.nb_mob = 1;
    mob->black.nb_mob = 1;
    mob->grey.nb_mob = 1;
    cond_ini_all(dwd, mob, to);
}
