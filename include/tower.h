/*
** EPITECH PROJECT, 2019
** defender
** File description:
** struct for tower
*/

#ifndef TOWER_
#define TOWER_

typedef struct money_text
{
    sfText *money_t;
    sfFont *money_f;
    sfVector2f pos_money;
    short upg_money;
    sfText *my_money_t;
    sfFont *my_money_f;
    sfVector2f pos_my_money;
} money_t;

typedef struct constructor
{
    int is_bought;
    int is_click;
    int pos_to;
    int money;
    sfSprite *construct_s;
    sfIntRect rect_construct;
    sfVector2f pos_construct;
    sfSprite *upgrade_s;
    sfIntRect rect_upgrade;
    sfVector2f pos_upgrade;
    sfSprite **towers_s;
    sfVector2f pos_tower;
    sfIntRect rect_tower;
    sfIntRect *rect_up_tower;
} construct_t;

typedef struct bank
{
    sfClock **clock;
    sfTime *time;
    float *sec;
} bank_t;

typedef struct mage
{
    sfClock **clock;
    sfTime *time;
    float *sec;
    sfClock **clockm;
    sfTime *timem;
    float *secm;
    sfSprite **spell;
} mage_t;

typedef struct moltar
{
    sfClock **clock;
    sfTime *time;
    float *sec;
    sfClock **clockm;
    sfTime *timem;
    float *secm;
    sfSprite **rock;
} moltar_t;

typedef struct projectile
{
    sfClock **clock;
    sfTime *time;
    float *sec;
    sfClock **clockm;
    sfTime *timem;
    float *secm;
    sfSprite **arrow;
    sfVector2f *pos_arrow;
    float *angle_arrow;
} projectile_t;


typedef struct tower
{
    int *tower;
    mage_t mage;
    moltar_t moltar;
    money_t money;
    bank_t bank;
    sfSprite *money_bar_s;
    projectile_t project;
    construct_t construct;
} to_t;

void malloc_clock_tower(to_t *to);
void set_size_projectile(to_t *to);
void bank_tower_condi(int i, to_t *to, int tower);
void malloc_clock_projectil(to_t *to);
int deal_money(int i, to_t *to);

#endif
