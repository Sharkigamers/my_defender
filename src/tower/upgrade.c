/*
** EPITECH PROJECT, 2019
** defender
** File description:
** upgrade
*/

#include "my.h"

void cond_upgrade_disp(to_t *to)
{
        to->money.pos_money.x = to->construct.pos_upgrade.x + 111;
        to->money.pos_money.y = to->construct.pos_upgrade.y + 45;
        sfText_setString(to->money.money_t, my_itoa(to->money.upg_money));
        sfText_setPosition(to->money.money_t, to->money.pos_money);
        check_price(to->tower[to->construct.pos_to], to);
}

void show_upgrade(int posx_min, int posy_min, to_t *to, dwd_t *dwd)
{
    int nb;

    if (dwd->event.type == sfEvtMouseButtonReleased &&
        dwd->mouse.mouse_pos.x > posx_min &&
        dwd->mouse.mouse_pos.x < posx_min + 97 &&
        dwd->mouse.mouse_pos.y > posy_min - 65 &&
        dwd->mouse.mouse_pos.y < posy_min + 42) {
        dwd->event.type = 0;
        to->construct.is_click = 2;
        to->construct.pos_upgrade.x = posx_min + 48 - 130;
        to->construct.pos_upgrade.y = posy_min + 18 - 125;
        sfSprite_setPosition
            (to->construct.upgrade_s, to->construct.pos_upgrade);
        nb = witch_to(to->construct.pos_upgrade.x, to->construct.pos_upgrade.y);
        cond_upgrade_disp(to);
        to->construct.pos_to = witch_to
            (to->construct.pos_upgrade.x, to->construct.pos_upgrade.y);
        if ((to->tower[nb] % 4) == 0)
            to->construct.is_click = 3;
    }
}

void click_destroy(to_t *to, dwd_t *dwd)
{
    sfVector2f spos = sfSprite_getPosition(to->construct.upgrade_s);

    to->construct.pos_to = witch_to(spos.x, spos.y);
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        (to->construct.is_click == 2 || to->construct.is_click == 3) &&
        dwd->mouse.mouse_pos.x > spos.x + 83 &&
        dwd->mouse.mouse_pos.x < spos.x + 165 &&
        dwd->mouse.mouse_pos.y > spos.y + 181 &&
        dwd->mouse.mouse_pos.y < spos.y + 249) {
        to->tower[to->construct.pos_to] = 0;
        dwd->event.type = 0;
        to->construct.is_click = 0;
    }
}

void click_upgrade(to_t *to, dwd_t *dwd)
{
    sfVector2f spos = sfSprite_getPosition(to->construct.upgrade_s);

    to->construct.pos_to = witch_to(spos.x, spos.y);
    check_price(to->tower[to->construct.pos_to], to);
    sfText_setString(to->money.money_t, my_itoa(to->money.upg_money));
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        (to->construct.money - to->money.upg_money > 0) &&
        to->construct.is_click == 2 && dwd->mouse.mouse_pos.x > spos.x + 82 &&
        dwd->mouse.mouse_pos.x < spos.x + 164 &&
        dwd->mouse.mouse_pos.y > spos.y &&
        dwd->mouse.mouse_pos.y < spos.y + 69) {
        to->construct.money -= to->money.upg_money;
        check_upgrade(to->tower[to->construct.pos_to], to);
        to->tower[to->construct.pos_to]++;
        dwd->event.type = 0;
    }
}
