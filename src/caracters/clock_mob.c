/*
** EPITECH PROJECT, 2019
** defender
** File description:
** clock_mob
*/

#include "my.h"

void run_game_clock(to_t *to, int i)
{
    to->project.time[i] = sfClock_getElapsedTime(to->project.clock[i]);
    to->project.sec[i] = to->project.time[i].microseconds / 1000000.0;
    to->project.timem[i] = sfClock_getElapsedTime(to->project.clockm[i]);
    to->project.secm[i] = to->project.timem[i].microseconds / 1000000.0;
    to->mage.time[i] = sfClock_getElapsedTime(to->mage.clock[i]);
    to->mage.sec[i] = to->mage.time[i].microseconds / 1000000.0;
    to->mage.timem[i] = sfClock_getElapsedTime(to->mage.clockm[i]);
    to->mage.secm[i] = to->mage.timem[i].microseconds / 1000000.0;
    to->bank.time[i] = sfClock_getElapsedTime(to->bank.clock[i]);
    to->bank.sec[i] = to->bank.time[i].microseconds / 1000000.0;
    to->moltar.time[i] = sfClock_getElapsedTime(to->moltar.clock[i]);
    to->moltar.sec[i] = to->moltar.time[i].microseconds / 1000000.0;
    to->moltar.timem[i] = sfClock_getElapsedTime(to->moltar.clockm[i]);
    to->moltar.secm[i] = to->moltar.timem[i].microseconds / 1000000.0;
}
