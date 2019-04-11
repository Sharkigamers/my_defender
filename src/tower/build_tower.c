/*
** EPITECH PROJECT, 2019
** defender
** File description:
** build tower
*/

#include "my.h"

void construction(int posx_min, int posy_min, to_t *to, dwd_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        dwd->mouse.mouse_pos.x > posx_min &&
        dwd->mouse.mouse_pos.x < posx_min + 97 &&
        dwd->mouse.mouse_pos.y > posy_min &&
        dwd->mouse.mouse_pos.y < posy_min + 36) {
        dwd->event.type = 0;
        to->construct.is_click = 1;
        to->construct.pos_construct.x = posx_min + 48 - 130;
        to->construct.pos_construct.y = posy_min + 18 - 125;
        sfSprite_setPosition
            (to->construct.construct_s, to->construct.pos_construct);
    }
}

void last_cond_show_constructor(to_t *to, dwd_t *dwd)
{
    if (to->construct.is_click == 3) {
        sfRenderWindow_drawSprite(dwd->window, to->construct.upgrade_s, NULL);
        to->construct.rect_upgrade.left = 740;
        sfSprite_setTextureRect
        (to->construct.upgrade_s, to->construct.rect_upgrade);
    }
}

void show_constructor(to_t *to, dwd_t *dwd, int nb)
{
    if (to->construct.is_click == 1)
        sfRenderWindow_drawSprite(dwd->window, to->construct.construct_s, NULL);
    if (to->construct.is_click == 2) {
        nb = witch_to(to->construct.pos_upgrade.x, to->construct.pos_upgrade.y);
        if ((to->tower[nb] % 4) == 0)
            to->construct.is_click = 3;
        else {
            sfRenderWindow_drawSprite
                (dwd->window, to->construct.upgrade_s, NULL);
            to->construct.rect_upgrade.left = 468;
            sfSprite_setTextureRect
                (to->construct.upgrade_s, to->construct.rect_upgrade);
            sfRenderWindow_drawText(dwd->window, to->money.money_t, NULL);
        }
    }
    last_cond_show_constructor(to, dwd);
}

void show_construction(to_t *to, dwd_t *dwd)
{
    sfVector2f get_pos = sfSprite_getPosition(to->construct.construct_s);
    int nb = 0;
    int no_more_to = 0;

    unpop_menu(to, dwd);
    whose_construction_map(to, dwd);
    buy_tower(dwd, to, get_pos);
    click_destroy(to, dwd);
    click_upgrade(to, dwd);
    disp_towers(to, dwd);
    to->construct.money > 999999 ? to->construct.money = 999999 : 0;
    for (int i = 0; to->tower[i] != -1; i++)
        to->tower[i] != 0 ? no_more_to++ : 0;
    to->construct.money < 70 && no_more_to == 0 ? to->construct.money = 70 : 0;
    sfText_setString(to->money.my_money_t, my_itoa(to->construct.money));
    sfRenderWindow_drawText(dwd->window, to->money.my_money_t, NULL);
    show_constructor(to, dwd, nb);
}
