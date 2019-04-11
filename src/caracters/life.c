/*
** EPITECH PROJECT, 2019
** life.c
** File description:
** anime and handle my life in game
*/

#include "my.h"

void ini_life(mob_t *mob)
{
    sfVector2f scl = {0.45, 0.45};

    mob->life.sec = malloc(sizeof(float) * 3);
    mob->life.time = malloc(sizeof(sfTime) * 3);
    mob->life.rect_life = malloc(sizeof(sfIntRect) * 3);
    mob->life.life_spr = malloc(sizeof(sfSprite *) * 3);
    mob->life.clock = malloc(sizeof(sfClock *) * 3);
    mob->life.life = 3;
    for (int i = 0; i < 3; i++) {
        mob->life.clock[i] = sfClock_create();
        mob->life.rect_life[i].left = 0;
        mob->life.rect_life[i].top = 0;
        mob->life.rect_life[i].height = 150;
        mob->life.rect_life[i].width = 150;
        mob->life.life_spr[i] = create_sprite
            ("./assets/mob/heart.png", 1780 - (i * 53), 50);
        sfSprite_setTextureRect(mob->life.life_spr[i], mob->life.rect_life[i]);
        sfSprite_setScale(mob->life.life_spr[i], scl);
    }
}

void anime_lose_life(mob_t *mob, int i)
{
    mob->life.time[i] = sfClock_getElapsedTime(mob->life.clock[i]);
    mob->life.sec[i] = mob->life.time[i].microseconds / 1000000.0;
    if (mob->life.sec[i] > 0.13 && mob->life.rect_life[i].left < 700) {
        mob->life.rect_life[i].left += 145;
        sfSprite_setTextureRect(mob->life.life_spr[i], mob->life.rect_life[i]);
        sfClock_restart(mob->life.clock[i]);
    }
}

void check_lose_life(mob_t *mob, int i)
{
    if (i <= 2)
        anime_lose_life(mob, 2);
    if (i <= 1)
        anime_lose_life(mob, 1);
    if (i <= 0)
        anime_lose_life(mob, 0);
}
