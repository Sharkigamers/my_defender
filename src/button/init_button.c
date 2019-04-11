/*
** EPITECH PROJECT, 2019
** defender
** File description:
** ini
*/

#include "my.h"

static void ini_sprites(dwd_t *dwd)
{
    dwd->mbutton.play_s = create_sprite
        ("assets/menu/menu_button.png", 715, 100);
    dwd->mbutton.shop_s = create_sprite
        ("assets/menu/menu_button.png", 745, 315);
    dwd->mbutton.story_s = create_sprite
        ("assets/menu/menu_button.png", 630, 550);
    dwd->mbutton.leave_s = create_sprite
        ("assets/menu/menu_button.png", 745, 815);
    dwd->mbutton.return_s = create_sprite
        ("assets/menu/menu_button.png", 1500, 850);
    dwd->mbutton.option_s = create_sprite
        ("assets/menu/button_option.png", 1500, 840);
    dwd->pbutton.easy_s = create_sprite
        ("assets/menu/map_button.png", 700, 50);
    dwd->pbutton.medium_s = create_sprite
        ("assets/menu/map_button.png", 745, 250);
    dwd->pbutton.hard_s = create_sprite
        ("assets/menu/map_button.png", 750, 500);
    dwd->pbutton.hell_s = create_sprite
        ("assets/menu/map_button.png", 730, 750);
}

static void ini_rect_menu(dwd_t *dwd)
{
    dwd->mbutton.rect_play.left = 11;
    dwd->mbutton.rect_play.top = 19;
    dwd->mbutton.rect_play.height = 155;
    dwd->mbutton.rect_play.width = 457;
    dwd->mbutton.rect_shop.left = 11;
    dwd->mbutton.rect_shop.top = 200;
    dwd->mbutton.rect_shop.height = 182;
    dwd->mbutton.rect_shop.width = 392;
    dwd->mbutton.rect_story.left = 11;
    dwd->mbutton.rect_story.top = 420;
    dwd->mbutton.rect_story.height = 205;
    dwd->mbutton.rect_story.width = 600;
    dwd->mbutton.rect_leave.left = 11;
    dwd->mbutton.rect_leave.top = 646;
    dwd->mbutton.rect_leave.height = 161;
    dwd->mbutton.rect_leave.width = 380;
    dwd->mbutton.rect_return.left = 10;
    dwd->mbutton.rect_return.top = 892;
    dwd->mbutton.rect_return.height = 164;
    dwd->mbutton.rect_return.width = 384;
}

static void ini_rect_play(dwd_t *dwd)
{
    dwd->pbutton.rect_easy.left = 4;
    dwd->pbutton.rect_easy.top = 8;
    dwd->pbutton.rect_easy.height = 185;
    dwd->pbutton.rect_easy.width = 458;
    dwd->pbutton.rect_medium.left = 4;
    dwd->pbutton.rect_medium.top = 192;
    dwd->pbutton.rect_medium.height = 232;
    dwd->pbutton.rect_medium.width = 415;
    dwd->pbutton.rect_hard.left = 4;
    dwd->pbutton.rect_hard.top = 440;
    dwd->pbutton.rect_hard.height = 218;
    dwd->pbutton.rect_hard.width = 434;
    dwd->pbutton.rect_hell.left = 4;
    dwd->pbutton.rect_hell.top = 654;
    dwd->pbutton.rect_hell.height = 264;
    dwd->pbutton.rect_hell.width = 460;
}

void set_rect(dwd_t *dwd)
{
    sfSprite_setTextureRect(dwd->mbutton.play_s, dwd->mbutton.rect_play);
    sfSprite_setTextureRect(dwd->mbutton.story_s, dwd->mbutton.rect_story);
    sfSprite_setTextureRect(dwd->mbutton.shop_s, dwd->mbutton.rect_shop);
    sfSprite_setTextureRect(dwd->mbutton.leave_s, dwd->mbutton.rect_leave);
    sfSprite_setTextureRect(dwd->mbutton.return_s, dwd->mbutton.rect_return);
    sfSprite_setTextureRect(dwd->mbutton.option_s, dwd->mbutton.rect_option);
    sfSprite_setTextureRect
        (dwd->option.music_button_s, dwd->option.rect_music_button);
    sfSprite_setTextureRect
        (dwd->option.music_bar_s, dwd->option.rect_music_bar);
    sfSprite_setTextureRect(dwd->pbutton.easy_s, dwd->pbutton.rect_easy);
    sfSprite_setTextureRect(dwd->pbutton.medium_s, dwd->pbutton.rect_medium);
    sfSprite_setTextureRect(dwd->pbutton.hard_s, dwd->pbutton.rect_hard);
    sfSprite_setTextureRect(dwd->pbutton.hell_s, dwd->pbutton.rect_hell);
}

void ini_button(dwd_t *dwd)
{
    ini_sprites(dwd);
    ini_other_sprites(dwd);
    ini_rect_menu(dwd);
    ini_other_rect_menu(dwd);
    ini_rect_play(dwd);
    ini_rect_pause(dwd);
    set_rect(dwd);
    set_other_rect(dwd);
}
