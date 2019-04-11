/*
** EPITECH PROJECT, 2019
** projectiles.c
** File description:
** create all my projectiles
*/

#include "my.h"


void malloc_clock_projectil(to_t *to)
{
    to->project.clockm = malloc(sizeof(sfClock *) * 7);
    to->project.timem = malloc(sizeof(sfTime) * 7);
    to->project.secm = malloc(sizeof(float) * 7);
    to->mage.clockm = malloc(sizeof(sfClock *) * 7);
    to->mage.timem = malloc(sizeof(sfTime) * 7);
    to->mage.secm = malloc(sizeof(float) * 7);
    to->moltar.clockm = malloc(sizeof(sfClock *) * 7);
    to->moltar.timem = malloc(sizeof(sfTime) * 7);
    to->moltar.secm = malloc(sizeof(float) * 7);
    to->project.pos_arrow = malloc(sizeof(sfVector2f) * 7);
    to->project.angle_arrow = malloc(sizeof(float) * 7);
    for (int i = 0; i != 6; i++) {
        to->project.clockm[i] = sfClock_create();
        to->moltar.clockm[i] = sfClock_create();
        to->mage.clockm[i] = sfClock_create();
        to->project.pos_arrow[i].x = -200;
        to->project.pos_arrow[i].y = -200;
        to->project.angle_arrow[i] = -45;
    }
}

void malloc_clock_second(to_t *to)
{
    to->moltar.clock = malloc(sizeof(sfClock *) * 7);
    to->moltar.time = malloc(sizeof(sfTime) * 7);
    to->moltar.sec = malloc(sizeof(float) * 7);
    to->project.clock = malloc(sizeof(sfClock *) * 7);
    to->project.time = malloc(sizeof(sfTime) * 7);
    to->project.sec = malloc(sizeof(float) * 7);
}

void first_alloc(to_t *to)
{
    to->project.arrow = malloc(sizeof(sfSprite *) * 7);
    to->mage.clock = malloc(sizeof(sfClock *) * 7);
    to->mage.time= malloc(sizeof(sfTime) * 7);
    to->mage.sec = malloc(sizeof(float) * 7);
    to->mage.spell = malloc(sizeof(sfSprite *) * 7);
    to->moltar.rock = malloc(sizeof(sfSprite *) * 7);
    to->bank.clock = malloc(sizeof(sfClock *) * 7);
    to->bank.time= malloc(sizeof(sfTime) * 7);
    to->bank.sec = malloc(sizeof(float) * 7);
}

void malloc_clock_tower(to_t *to)
{
    malloc_clock_projectil(to);
    malloc_clock_second(to);
    first_alloc(to);
    for (int i = 0; i != 6; i++) {
        to->project.clock[i] = sfClock_create();
        to->mage.clock[i] = sfClock_create();
        to->bank.clock[i] = sfClock_create();
        to->moltar.clock[i] = sfClock_create();
        to->project.arrow[i] = create_sprite
            ("./assets/gameplay/arrow.png", -200, -200);
        to->mage.spell[i] = create_sprite
            ("./assets/gameplay/spell.png", -200, -200);
        to->moltar.rock[i] = create_sprite
            ("./assets/gameplay/rock.png", -200, -200);
    }
    set_size_projectile(to);
}

void set_size_projectile(to_t *to)
{
    sfVector2f scl;

    scl.x = 0.4;
    scl.y = 0.4;
    for (int i = 0; i != 6; i++) {
        sfSprite_setScale(to->project.arrow[i], scl);
    }
    scl.x = 1.2;
    scl.y = 1.2;
    for (int i = 0; i != 6; i++) {
        sfSprite_setScale(to->mage.spell[i], scl);
    }
}
