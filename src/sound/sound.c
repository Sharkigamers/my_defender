/*
** EPITECH PROJECT, 2019
** sound.c
** File description:
** create my sound
*/

#include "my.h"

sfMusic *create_sound(char *path, sfBool i, int volume)
{
    sfMusic *s;

    s = sfMusic_createFromFile(path);
    sfMusic_setVolume(s, volume);
    sfMusic_setLoop(s, i);
    return (s);
}

void play_menu_song(dwd_t *dwd)
{
    dwd->sound.wich_music = 0;
    dwd->option.volume = 50;
    dwd->sound.menu = create_sound("./assets/sound/epic.ogg", sfTrue, 50);
    dwd->sound.forest = create_sound("./assets/sound/forest.ogg", sfTrue, 50);
    dwd->sound.epic = create_sound("./assets/sound/menu.ogg", sfTrue, 50);
    dwd->sound.storm = create_sound("./assets/sound/storm.ogg", sfFalse, 80);
    dwd->sound.freeze = create_sound("./assets/sound/ice.ogg", sfFalse, 80);
    dwd->sound.acid = create_sound("./assets/sound/acid.ogg", sfFalse, 80);
    dwd->sound.click = create_sound("./assets/sound/click.ogg", sfFalse, 50);
    dwd->sound.arrow = create_sound("./assets/sound/arrow.ogg", sfFalse, 50);
    dwd->sound.elec = create_sound("./assets/sound/electric.ogg", sfFalse, 50);
    dwd->sound.rock = create_sound("./assets/sound/rock.ogg", sfFalse, 50);
    sfMusic_play(dwd->sound.menu);
}

void cond_option_volume_sound(dwd_t *dwd)
{
    switch (dwd->sound.wich_music) {
    case 5:
        cond_music_button(dwd, dwd->sound.snow);
        break;
    case 8:
        cond_music_button(dwd, dwd->sound.epic3);
        break;
    case 7:
        cond_music_button(dwd, dwd->sound.hell);
        break;
    case 0:
        cond_music_button(dwd, dwd->sound.menu);
        break;
    }
}

void option_volume_sound(dwd_t *dwd)
{
    switch (dwd->sound.wich_music) {
    case 2:
        cond_music_button(dwd, dwd->sound.epic);
        break;
    case 1:
        cond_music_button(dwd, dwd->sound.forest);
        break;
    case 4:
        cond_music_button(dwd, dwd->sound.epic1);
        break;
    case 3:
        cond_music_button(dwd, dwd->sound.desert);
        break;
    case 6:
        cond_music_button(dwd, dwd->sound.epic1);
        break;
    }
    cond_option_volume_sound(dwd);
}
