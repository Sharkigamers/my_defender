/*
** EPITECH PROJECT, 2019
** attack.c
** File description:
** create my attakc function
*/

#include "my.h"

void annex_condi_attackrg(mob_t *mob, int i, to_t *to, int tower)
{
    for (int j = 0; j < mob->green.nb_mob; j++) {
        if (tower == 1 ||tower == 2 ||tower == 3 || tower == 4)
            arrow_tower_condi(&mob->green.life[j], mob->green.posspr[j], i, to);
        if (tower == 13 || tower == 14 || tower == 15 || tower == 16)
            mage_tower_condi(&mob->green.life[j], mob->green.posspr[j], i, to);
        if (tower == 5 || tower == 6 || tower == 7 || tower == 8)
            moltar_tower_condi
                (&mob->green.life[j], mob->green.posspr[j], i, to);
        if (mob->green.life[j] < 0) {
            mob->green.posspr[j].y = 5000;
            sfSprite_setPosition(mob->green.sprite[j], mob->green.posspr[j]);
        }
    }
}

void condi_attackrg(mob_t *mob, int i, to_t *to, int tower)
{
    for (int j = 0; j < mob->red.nb_mob; j++) {
        if (tower == 1 ||tower == 2 ||tower == 3 || tower == 4)
            arrow_tower_condi(&mob->red.life[j], mob->red.posspr[j], i, to);
        if (tower == 13 || tower == 14 || tower == 15 || tower == 16)
            mage_tower_condi(&mob->red.life[j], mob->red.posspr[j], i, to);
        if (tower == 5 || tower == 6 || tower == 7 || tower == 8)
            moltar_tower_condi(&mob->red.life[j], mob->red.posspr[j], i, to);
        if (mob->red.life[j] < 0) {
            mob->red.posspr[j].y = 5000;
            sfSprite_setPosition(mob->red.sprite[j], mob->red.posspr[j]);
        }
    }
    annex_condi_attackrg(mob, i, to, tower);
}

void cond_attack(int i, mob_t *mob, int tower, to_t *to)
{
    for (int j = 0; j < mob->grey.nb_mob; j++) {
        if (tower == 1 ||tower == 2 ||tower == 3 || tower == 4)
            arrow_tower_condi(&mob->grey.life[j], mob->grey.posspr[j], i, to);
        if (tower == 13 || tower == 14 || tower == 15 || tower == 16)
            mage_tower_condi(&mob->grey.life[j], mob->grey.posspr[j], i, to);
        if (tower == 5 || tower == 6 || tower == 7 || tower == 8)
            moltar_tower_condi(&mob->grey.life[j], mob->grey.posspr[j], i, to);
        if (mob->grey.life[j] < 0) {
            mob->grey.posspr[j].y = 5000;
            sfSprite_setPosition(mob->grey.sprite[j], mob->grey.posspr[j]);
        }
    }
}

void attack(int i, mob_t *mob, int tower, to_t *to)
{
    condi_attackrg(mob, i, to, tower);
    for (int j = 0; j < mob->black.nb_mob; j++) {
        if (tower == 1 ||tower == 2 ||tower == 3 || tower == 4)
            arrow_tower_condi(&mob->black.life[j], mob->black.posspr[j], i, to);
        if (tower == 13 || tower == 14 || tower == 15 || tower == 16)
            mage_tower_condi(&mob->black.life[j], mob->black.posspr[j], i, to);
        if (tower == 5 || tower == 6 || tower == 7 || tower == 8)
            moltar_tower_condi
                (&mob->black.life[j], mob->black.posspr[j], i, to);
        if (mob->black.life[j] < 0) {
            mob->black.posspr[j].y = 5000;
            mob->black.posspr[j].y = 5001;
            sfSprite_setPosition(mob->black.sprite[j], mob->black.posspr[j]);
        }
    }
    cond_attack(i, mob, tower, to);
    bank_tower_condi(i, to, tower);
}

void check_range(to_t *to, mob_t *mob)
{
    for (int i = 0; i < 6; i++) {
        run_game_clock(to, i);
        attack(i, mob, to->tower[i], to);
    }
}
