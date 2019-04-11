/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** protos
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "window.h"
#include "mymob.h"
#include "tower.h"

#ifndef MY_
#define MY_

/* lib */

int my_strcmp(char const *s1, char const *s2);
int my_atoi(char const *str);
char *my_itoa(int nb);
char *my_strcpy(char *str, char const *s);

/* defender */

sfSprite *create_sprite(char *path, float x, float y);

/* window */

sfRenderWindow *create_mywindow(unsigned int width, unsigned int height);
void ini_mouse(dwd_t *dwd);
void mouse(dwd_t *dwd);

/* loading */

void loading_window(dwd_t *dwd, mob_t *mob, to_t *to);

/* main */

int defender(void);
void destroy_all(dwd_t *dwd, mob_t *mob, to_t *to);

/* innit */

void ini_all(dwd_t *dwd, mob_t *mob, to_t *to);
void first(dwd_t *dwd, to_t *to, sfIntRect *left);
void second(dwd_t *dwd, mob_t *mob, to_t *to, sfIntRect *left);
void three(dwd_t *dwd, mob_t *mob, to_t *to, sfIntRect *left);
void ini_menu(dwd_t *dwd);
void ini_button(dwd_t *dwd);
void ini_other_rect_menu(dwd_t *dwd);
void ini_other_sprites(dwd_t *dwd);
void reini_before_menu(dwd_t *dwd, to_t *to, mob_t *mob);
void ini_life(mob_t *mob);
void ini_htp(dwd_t *dwd);
void reini_before_menu(dwd_t *dwd, to_t *to, mob_t *mob);
void ini_game_clock(dwd_t *dwd);
void first(dwd_t *dwd, to_t *to, sfIntRect *left);

/* menu */

void event_in_menu(dwd_t *dwd);
void disp_menu(dwd_t *dwd);
void anime_menu(dwd_t *dwd);
void show_menu(dwd_t *dwd, to_t *to, mob_t *mob);
void show_menu_play(dwd_t *dwd, to_t *to);
void show_shop(dwd_t *dwd);
void show_story(dwd_t *dwd);
void show_option(dwd_t *dwd);
void cond_play(dwd_t *dwd);
void cond_shop(dwd_t *dwd);
void cond_story(dwd_t *dwd);
void cond_leave(dwd_t *dwd);
void cond_option(dwd_t *dwd);
void cond_easy(dwd_t *dwd, to_t *to);
void cond_medium(dwd_t *dwd,to_t *to);
void cond_hard(dwd_t *dwd, to_t *to);
void cond_hell(dwd_t *dwd, to_t *to);
int cond_return(dwd_t *dwd);
void cond_music_button(dwd_t *dwd, sfMusic *music);
void cond_cursor(dwd_t *dwd);
void disp_bck_pause(dwd_t *dwd);
void cond_htp(dwd_t *dwd);
void show_menu_htp(dwd_t *dwd);
void cond_menu(dwd_t *dwd, to_t *to);
void anime_menu(dwd_t *dwd);

/* music */

void play_menu_song(dwd_t *dwd);
void chose_music(dwd_t *dwd);
void all_pause(dwd_t *dwd);
void option_volume_sound(dwd_t *dwd);

/* gameplay */

void annex_gameplay(dwd_t *dwd, mob_t *mob, to_t *to);
void use_game_clock(dwd_t *dwd);
void event_in_gameplay(dwd_t *dwd);
void music_by_map(dwd_t *dwd);
void main_game(dwd_t *dwd, mob_t *mob, to_t *to);
int check_launch_wave(dwd_t *dwd, mob_t *mob, int j);
void print_redmob(dwd_t *dwd, mob_t *mob);
void check_lose_life(mob_t *mob, int i);
void run_game_clock(to_t *to, int i);
int sendm_projectile(sfVector2f postower, sfVector2f pos, int i, to_t *to);
float speedm_increase(int i);
int send_projectile(sfVector2f postower, sfVector2f pos, to_t *to, int i);
void annex_project(int i, to_t *to, sfVector2f pos);
int annex_send_projectile(int i, to_t *to, int *a, sfVector2f pos);
int send_rock_projectile(sfVector2f postower, sfVector2f pos, int i, to_t *to);
void move_to_posr(sfVector2f *move, sfVector2f to, float speed);
void move_to_pos(sfVector2f *move, sfVector2f to, float speed, float *angle);
void arrow_tower_condi(int *life, sfVector2f pos, int i, to_t *to);
void bank_tower_condi(int i, to_t *to, int tower);
void mage_tower_condi(int *life, sfVector2f pos, int i, to_t *to);
void moltar_tower_condi(int *life, sfVector2f pos, int i, to_t *to);
void change_to_big_arrow(int i, to_t *to);
float speed_increase(to_t *to, int i);
float moltar_increase(int i);
void start_check_end_wave(mob_t *mob);
int check_end_wave(mob_t *mob);
void next_wave(mob_t *mob);
int check_launch_wave(dwd_t *dwd, mob_t *mob, int j);
int check_enemy_alive(mob_t *mob);
void free_wave(mob_t *mob);
void create_wave(mob_t *mob);
void annex_create_wave(mob_t *mob);
void malloc_wave(mob_t *mob);
int annex_check_pos(to_t *to, int type_tower, sfVector2f pos);

/* pause */

void show_pause(dwd_t *dwd);
void ini_rect_pause(dwd_t *dwd);
void set_other_rect(dwd_t *dwd);
void cond_resume(dwd_t *dwd);
void cond_pause_option(dwd_t *dwd);
void cond_pause_menu(dwd_t *dwd);
void cond_music(dwd_t *dwd);
void show_pause_option(dwd_t *dwd);
void confirm_menu(dwd_t *dwd);
void cond_confirm_leave(dwd_t *dwd);
void cond_confirm_return(dwd_t *dwd);
void cond_confirm_pause_menu(dwd_t *dwd);

/* construction */

void ini_building(to_t *to, int i);
void ini_constructor(to_t *to);
void show_construction(to_t *to, dwd_t *dwd);
void buy_arc_tower(dwd_t *dwd, to_t *to, sfVector2f get_pos);
void buy_cannon_tower(dwd_t *dwd, to_t *to, sfVector2f get_pos);
void buy_def_tower(dwd_t *dwd, to_t *to, sfVector2f spos);
void buy_mage_tower(dwd_t *dwd, to_t *to, sfVector2f spos);
int check_pos(to_t *to, int type_tower, sfVector2f pos);
void forest_constrcut(to_t *to, dwd_t *dwd);
void buy_tower(dwd_t *dwd, to_t *to, sfVector2f get_pos);
void construction(int posx_min, int posy_min, to_t *to, dwd_t *dwd);
void whose_construction_map(to_t *to, dwd_t *dwd);
void disp_towers(to_t *to, dwd_t *dwd);
void special_memset(to_t *to, int i);
int witch_to(int xmin, int ymin);
void show_upgrade(int posx_min, int posy_min, to_t *to, dwd_t *dwd);
void forest_upgrade(to_t *to, dwd_t *dwd);
void click_destroy(to_t *to, dwd_t *dwd);
void click_upgrade(to_t *to, dwd_t *dwd);
void check_upgrade(int lvl, to_t *to);
void unpop_menu(to_t *to, dwd_t *dwd);
void ini_money(to_t *to);
void check_price(int lvl, to_t *to);

/* tower attack */
void check_range(to_t *to, mob_t *mob);
int send_projectile(sfVector2f pos, sfVector2f posi, to_t *to, int i);
int sendm_projectile(sfVector2f pos, sfVector2f posi, int i, to_t *to);
void arrow_tower_condi(int *life, sfVector2f posi, int i, to_t *to);
void mage_tower_condi(int *life, sfVector2f posi, int i, to_t *to);
void moltar_tower_condi(int *life, sfVector2f posi, int i, to_t *to);
float speedm_increase(int i);
int send_rock_projectile(sfVector2f pos, sfVector2f posi, int i, to_t *to);
/* spell */

void ini_text_spell(mob_t *mob);
void ini_spell(mob_t *mob);
void disp_spell(mob_t *mob, dwd_t *dwd);
void check_hitbox(dwd_t *dwd, mob_t *mob);
void annex_spell(mob_t *mob);
void disp_dropped_spell_one(mob_t *mob, dwd_t *dwd);
void disp_dropped_spell_two(mob_t *mob, dwd_t *dwd);
void disp_dropped_spell_tree(mob_t *mob, dwd_t *dwd);
void cooldown(mob_t *mob, dwd_t *dwd);

/* end */

void end_menu(dwd_t *dwd);
void inu_end_menu(dwd_t *dwd);

#endif
