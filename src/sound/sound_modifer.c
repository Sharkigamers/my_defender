/*
** EPITECH PROJECT, 2019
** defender
** File description:
** sound modifer
*/

#include "my.h"

void annex_chose_music(dwd_t *dwd)
{
    switch (dwd->sound.wich_music) {
    case 7:
        sfMusic_stop(dwd->sound.epic);
        sfMusic_play(dwd->sound.forest);
        sfMusic_setVolume(dwd->sound.forest, dwd->option.volume);
        break;
    case 8:
        sfMusic_stop(dwd->sound.forest);
        sfMusic_play(dwd->sound.epic);
        sfMusic_setVolume(dwd->sound.epic, dwd->option.volume);
        break;
    }
}

void other_annex_music(dwd_t *dwd)
{
    switch (dwd->sound.wich_music) {
    case 4:
        sfMusic_stop(dwd->sound.forest);
        sfMusic_play(dwd->sound.epic);
        sfMusic_setVolume(dwd->sound.epic, dwd->option.volume);
        break;
    case 5:
        sfMusic_stop(dwd->sound.epic);
        sfMusic_play(dwd->sound.forest);
        sfMusic_setVolume(dwd->sound.forest, dwd->option.volume);
        break;
    case 6:
        sfMusic_stop(dwd->sound.forest);
        sfMusic_play(dwd->sound.epic);
        sfMusic_setVolume(dwd->sound.epic, dwd->option.volume);
        break;
    }
}

void chose_music(dwd_t *dwd)
{
    switch (dwd->sound.wich_music) {
    case 1:
        sfMusic_stop(dwd->sound.epic);
        sfMusic_play(dwd->sound.forest);
        sfMusic_setVolume(dwd->sound.forest, dwd->option.volume);
        break;
    case 2:
        sfMusic_stop(dwd->sound.forest);
        sfMusic_play(dwd->sound.epic);
        sfMusic_setVolume(dwd->sound.epic, dwd->option.volume);
        break;
    case 3:
        sfMusic_stop(dwd->sound.epic);
        sfMusic_play(dwd->sound.forest);
        sfMusic_setVolume(dwd->sound.forest, dwd->option.volume);
        break;
    }
    other_annex_music(dwd);
    annex_chose_music(dwd);
}

void all_pause(dwd_t *dwd)
{
    sfMusic_stop(dwd->sound.epic);
    sfMusic_stop(dwd->sound.forest);
}
