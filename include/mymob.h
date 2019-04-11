/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** protos
*/

#ifndef MYMOB_H
#define MYMOB_H

typedef struct spell
{
    sfText *spell1_t;
    sfText *spell2_t;
    sfText *spell3_t;
    int *is_click;
    sfSprite *spell1_s;
    sfIntRect rect_spell1;
    sfVector2f pos_spell1;
    sfSprite *spell2_s;
    sfIntRect rect_spell2;
    sfVector2f pos_spell2;
    sfSprite *spell3_s;
    sfIntRect rect_spell3;
    sfVector2f pos_spell3;
    sfClock **clock;
    sfTime *time;
    float *sec;
    sfSprite *icon1;
    sfSprite *icon2;
    sfSprite *icon3;
} spell_t;

typedef struct life
{
    sfSprite **life_spr;
    sfClock **clock;
    sfIntRect *rect_life;
    sfTime *time;
    float *sec;
    int life;
} life_t;

typedef struct init
{
    sfSprite *icon;
    sfSprite *iconh;
    sfVector2f *pos;
} init_t;

typedef struct redmob
{
    sfClock *clock;
    sfSprite **sprite;
    sfVector2f *posspr;
    int *life;
    int *check_posspr;
    int nb_mob;
} redmob_t;

typedef struct greymob
{
    sfClock *clock;
    sfSprite **sprite;
    sfVector2f *posspr;
    int *life;
    int *check_posspr;
    int nb_mob;
} greymob_t;

typedef struct blackmob
{
    sfClock *clock;
    sfSprite **sprite;
    sfVector2f *posspr;
    int *check_posspr;
    int nb_mob;
    int *life;
} blackmob_t;

typedef struct green
{
    sfClock *clock;
    sfSprite **sprite;
    sfVector2f *posspr;
    int *check_posspr;
    int *life;
    int nb_mob;
} greenmob_t;

typedef struct mob
{
    life_t life;
    redmob_t red;
    init_t init;
    greymob_t grey;
    greenmob_t green;
    blackmob_t black;
    spell_t spell;
} mob_t;

void create_mymob_spr(mob_t *mob);
void anime_red(mob_t *mob);
void anime_lose_life(mob_t *mob, int i);
void next_wave(mob_t *mob);
void create_wave(mob_t *mob);
int check_end_wave(mob_t *mob);

void anime_rmob(sfClock *clock, int i, mob_t *mob, int j);
void anime_gmob(sfClock *clock, int i, mob_t *mob, int j);
void anime_bmob(sfClock *clock, int i, mob_t *mob, int j);
void anime_grmob(sfClock *clock, int i, mob_t *mob, int j);
void mover_on_map(mob_t *mob, sfVector2f *pos, int i, int *map);
void moveg_on_map(mob_t *mob, sfVector2f *pos, int i, int *map);
void moveb_on_map(mob_t *mob, sfVector2f *pos, int i, int *map);
void movegr_on_map(mob_t *mob, sfVector2f *pos, int i, int *map);
void init_life_mob(mob_t *mob);
void fill_life_mob(mob_t *mob);

void check_hitbox_snow(sfSprite *sprite, mob_t *mob);
void check_hitbox_fire(sfSprite *sprite, mob_t *mob);
void check_hitbox_acid(sfSprite *sprite, mob_t *mob);

#endif
