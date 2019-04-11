/*
** EPITECH PROJECT, 2019
** defender
** File description:
** destroy
*/

#include "my.h"

void destroy_music(dwd_t *dwd)
{
    sfMusic_destroy(dwd->sound.menu);
    sfMusic_destroy(dwd->sound.forest);
    sfMusic_destroy(dwd->sound.epic);
    sfMusic_destroy(dwd->sound.storm);
    sfMusic_destroy(dwd->sound.freeze);
    sfMusic_destroy(dwd->sound.acid);
    sfMusic_destroy(dwd->sound.click);
    sfMusic_destroy(dwd->sound.arrow);
    sfMusic_destroy(dwd->sound.elec);
    sfMusic_destroy(dwd->sound.rock);
}

void destroy_all(dwd_t *dwd, mob_t *mob, to_t *to)
{
    destroy_music(dwd);
}
