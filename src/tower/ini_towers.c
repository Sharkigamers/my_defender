/*
** EPITECH PROJECT, 2019
** defender
** File description:
** ini_towers
*/

#include "my.h"

void ini_building(to_t *to, int i)
{
    int j;

    to->construct.towers_s = malloc(sizeof(sfSprite *) * i);
    for (j = 0; j < i; j++)
        to->construct.towers_s[j] = create_sprite
        ("assets/gameplay/towers.png", 0, 0);
    to->tower = malloc(sizeof(int) * (i + 1));
    for (j = 0; j < i; j++)
        to->tower[j] = 0;
    to->tower[j] = -1;
}

void special_memset(to_t *to, int i)
{
    int j;

    if (i > 20) {
        write(2, "Error: From the game tower allocation\n", 38);
        return;
    }
    for (j = 0; j < i; j++)
        to->tower[j] = 0;
    to->tower[j] = -1;
}

void ini_constructor(to_t *to)
{
    to->construct.construct_s = create_sprite
        ("assets/gameplay/towers.png", 0, 0);
    to->construct.rect_construct.left = 0;
    to->construct.rect_construct.top = 0;
    to->construct.rect_construct.height = 250;
    to->construct.rect_construct.width = 260;
    sfSprite_setTextureRect
        (to->construct.construct_s, to->construct.rect_construct);
    to->construct.upgrade_s = create_sprite
        ("assets/gameplay/towers.png", 0, 0);
    to->construct.rect_upgrade.left = 468;
    to->construct.rect_upgrade.top = 13;
    to->construct.rect_upgrade.height = 252;
    to->construct.rect_upgrade.width = 244;
    sfSprite_setTextureRect
        (to->construct.upgrade_s, to->construct.rect_upgrade);
    to->money_bar_s = create_sprite
        ("assets/gameplay/baner.png", 1600, 20);
}

void ini_money(to_t *to)
{
    to->construct.money = 0;
    to->money.money_f = sfFont_createFromFile("assets/text/Questrian 2.otf");
    to->money.money_t = sfText_create();
    sfText_setFont(to->money.money_t, to->money.money_f);
    sfText_setColor(to->money.money_t, sfGreen);
    sfText_setCharacterSize(to->money.money_t, 18);
    to->money.my_money_f = sfFont_createFromFile("assets/text/Questrian 2.otf");
    to->money.my_money_t = sfText_create();
    sfText_setFont(to->money.my_money_t, to->money.my_money_f);
    sfText_setColor(to->money.my_money_t, sfYellow);
    sfText_setCharacterSize(to->money.money_t, 18);
    to->money.pos_my_money.x = 1730;
    to->money.pos_my_money.y = 110;
    sfText_setPosition(to->money.my_money_t, to->money.pos_my_money);
}
