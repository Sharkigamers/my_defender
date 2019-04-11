/*
** EPITECH PROJECT, 2019
** defender
** File description:
** annex ini button
*/

#include "my.h"

void ini_other_sprites(dwd_t *dwd)
{
    dwd->option.music_button_s = create_sprite
        ("assets/menu/button_option.png", 730, 400);
    dwd->option.music_bar_s = create_sprite
        ("assets/menu/sound_bar.png", 755, 260);
    dwd->pause.pause = 0;
    dwd->pause.pause_s = create_sprite("assets/menu/pause_board.png", 510, 90);
    dwd->pause.resume_s = create_sprite
        ("assets/menu/button_option.png", 805, 220);
    dwd->pause.music_s = create_sprite
        ("assets/menu/button_option.png", 805, 510);
    dwd->pause.menu_s = create_sprite
        ("assets/menu/button_option.png", 803, 650);
    dwd->pbutton.htp_s = create_sprite
        ("assets/menu/button_option.png", 100, 800);
}

void ini_other_rect_menu(dwd_t *dwd)
{
    dwd->mbutton.rect_option.left = 10;
    dwd->mbutton.rect_option.top = 10;
    dwd->mbutton.rect_option.height = 156;
    dwd->mbutton.rect_option.width = 356;
    dwd->option.rect_music_button.left = 10;
    dwd->option.rect_music_button.top = 190;
    dwd->option.rect_music_button.height = 178;
    dwd->option.rect_music_button.width = 470;
    dwd->option.rect_music_bar.left = 0;
    dwd->option.rect_music_bar.top = 0;
    dwd->option.rect_music_bar.height = 138;
    dwd->option.rect_music_bar.width = 386;
    dwd->pbutton.rect_htp.left = 10;
    dwd->pbutton.rect_htp.top = 880;
    dwd->pbutton.rect_htp.height = 155;
    dwd->pbutton.rect_htp.width = 345;
}

void ini_rect_pause(dwd_t *dwd)
{
    dwd->pause.rect_resume.left = 12;
    dwd->pause.rect_resume.top = 402;
    dwd->pause.rect_resume.height = 136;
    dwd->pause.rect_resume.width = 328;
    dwd->pause.rect_music.left = 12;
    dwd->pause.rect_music.top = 724;
    dwd->pause.rect_music.height = 146;
    dwd->pause.rect_music.width = 324;
    dwd->pause.rect_menu.left = 12;
    dwd->pause.rect_menu.top = 566;
    dwd->pause.rect_menu.height = 144;
    dwd->pause.rect_menu.width = 340;
}

void set_other_rect(dwd_t *dwd)
{
    sfSprite_setTextureRect(dwd->pause.resume_s, dwd->pause.rect_resume);
    sfSprite_setTextureRect(dwd->pause.music_s, dwd->pause.rect_music);
    sfSprite_setTextureRect(dwd->pause.menu_s, dwd->pause.rect_menu);
    sfSprite_setTextureRect(dwd->pbutton.htp_s, dwd->pbutton.rect_htp);
}
