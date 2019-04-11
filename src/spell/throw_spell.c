/*
** EPITECH PROJECT, 2019
** defender
** File description:
** throw spell
*/

#include "my.h"

void sound_spells(dwd_t *dwd, int i, mob_t *mob)
{
    switch (mob->spell.is_click[i]) {
    case -1:
        sfMusic_play(dwd->sound.storm);
        break;
    case -2:
        sfMusic_play(dwd->sound.freeze);
        break;
    case -3:
        sfMusic_play(dwd->sound.acid);
        break;
    }
}

void disp_drop(dwd_t *dwd, mob_t *mob)
{
    for (int i = 0; i < 3; i++) {
        if (mob->spell.is_click[i] >= 1 &&
            dwd->event.type == sfEvtMouseButtonReleased &&
            dwd->mouse.pos.x >= 707 && dwd->mouse.pos.x <= 1200 &&
            dwd->mouse.pos.y >= 902 && dwd->mouse.pos.y <= 1080) {
            dwd->event.type = 0;
            mob->spell.is_click[i] = 0;
            return;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (mob->spell.is_click[i] >= 1 &&
            dwd->event.type == sfEvtMouseButtonReleased &&
            (dwd->mouse.pos.x < 707 || dwd->mouse.pos.x > 1200 ||
             dwd->mouse.pos.y < 902 || dwd->mouse.pos.y > 1080)) {
            mob->spell.is_click[i] *= -1;
            mob->spell.is_click[i + 3] = 0;
            sound_spells(dwd, i, mob);
        }
    }
}

void disp_drag(dwd_t *dwd, mob_t *mob)
{
    if (mob->spell.is_click[0] == 1) {
        mob->spell.pos_spell1.x = dwd->mouse.pos.x - 64;
        mob->spell.pos_spell1.y = dwd->mouse.pos.y - 68;
        sfSprite_setPosition(mob->spell.spell1_s, mob->spell.pos_spell1);
        sfRenderWindow_drawSprite(dwd->window, mob->spell.spell1_s, NULL);
    }
    if (mob->spell.is_click[1] == 2) {
        mob->spell.pos_spell2.x = dwd->mouse.pos.x - 68;
        mob->spell.pos_spell2.y = dwd->mouse.pos.y - 63;
        sfSprite_setPosition(mob->spell.spell2_s, mob->spell.pos_spell2);
        sfRenderWindow_drawSprite(dwd->window, mob->spell.spell2_s, NULL);
    }
    if (mob->spell.is_click[2] == 3) {
        mob->spell.pos_spell3.x = dwd->mouse.pos.x - 84;
        mob->spell.pos_spell3.y = dwd->mouse.pos.y - 159;
        sfSprite_setPosition(mob->spell.spell3_s, mob->spell.pos_spell3);
        sfRenderWindow_drawSprite(dwd->window, mob->spell.spell3_s, NULL);
    }
}

void check_first_hitbox(dwd_t *dwd, mob_t *mob, int val1, int val2)
{
    if (dwd->event.type == sfEvtMouseButtonPressed && val1 == 1 &&
        dwd->mouse.pos.x >= 707 && dwd->mouse.pos.x <= 798 &&
        dwd->mouse.pos.y >= 902 && dwd->mouse.pos.y <= 996) {
        mob->spell.rect_spell1.left = 92;
        mob->spell.rect_spell1.top = 750;
        mob->spell.rect_spell1.height = 137;
        mob->spell.rect_spell1.width = 128;
        sfSprite_setTextureRect(mob->spell.spell1_s, mob->spell.rect_spell1);
        mob->spell.is_click[0] = 1;
    }
    if (dwd->event.type == sfEvtMouseButtonPressed && val2 == 1 &&
        dwd->mouse.pos.x >= 910 && dwd->mouse.pos.x <= 1000 &&
        dwd->mouse.pos.y >= 902 && dwd->mouse.pos.y <= 996) {
        mob->spell.rect_spell2.left = 610;
        mob->spell.rect_spell2.top = 790;
        mob->spell.rect_spell2.height = 126;
        mob->spell.rect_spell2.width = 160;
        sfSprite_setTextureRect(mob->spell.spell2_s, mob->spell.rect_spell2);
        mob->spell.is_click[1] = 2;
    }
}
void check_hitbox(dwd_t *dwd, mob_t *mob)
{
    check_first_hitbox
        (dwd, mob, mob->spell.is_click[3], mob->spell.is_click[4]);
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        mob->spell.is_click[5] == 1 &&
        dwd->mouse.pos.x >= 1109 && dwd->mouse.pos.x <= 1200 &&
        dwd->mouse.pos.y >= 902 && dwd->mouse.pos.y <= 996) {
        mob->spell.rect_spell3.left = 356;
        mob->spell.rect_spell3.top = 684;
        mob->spell.rect_spell3.height = 219;
        mob->spell.rect_spell3.width = 169;
        sfSprite_setTextureRect(mob->spell.spell3_s, mob->spell.rect_spell3);
        mob->spell.is_click[2] = 3;
    }
    disp_drop(dwd, mob);
    disp_drag(dwd, mob);
    disp_dropped_spell_tree(mob, dwd);
    disp_dropped_spell_two(mob, dwd);
    disp_dropped_spell_one(mob, dwd);
    cooldown(mob, dwd);
}
