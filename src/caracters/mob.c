/*
** EPITECH PROJECT, 2019
** mob.c
** File description:
** create my sprites for my_mobs
*/

#include "my.h"
#include "time.h"

void annex_read_map(mob_t *mob, int *a, char **stock)
{
    int j = 0;
    int i = 0;

    while (j != 21) {
        if (stock[j][i] == '2') {
            mob->init.pos[*a].x = i * 10;
            mob->init.pos[*a].y = j * 25;
            (*a)++;
        }
        if (j == 20 && i != 192) {
            j = 0;
            i++;
        }
        else
            j++;
    }
}

void read_map_path(mob_t *mob)
{
    FILE *fd = fopen("./src/caracters/path1.txt", "r");
    char *s = malloc(10000);
    char **stock = malloc(sizeof(char *) * (10000));
    size_t len = 0;
    int j = 0;
    int a = 0;

    stock[0] = malloc(sizeof(char) * 10000);
    if (fd == NULL)
        return;
    for (j = 0; j != 38; j++) {
        getline(&s, &len, fd);
        stock[j] = malloc(sizeof(char) * 10000);
        my_strcpy(stock[j], s);
    }
    stock[j] = NULL;
    mob->init.pos = malloc(sizeof(sfVector2f) * 10);
    annex_read_map(mob, &a, stock);
}

void create_gameplay_spr(mob_t *mob)
{
    mob->init.icon = create_sprite("./assets/map/waveicon.png", 20, 30);
    mob->init.iconh = create_sprite("./assets/map/waveicon2.png", 20, 30);
}

void create_mob_spr(mob_t *mob, sfVector2f scl)
{
    sfIntRect rect = {0, 0, 300, 300};

    for (int i = 0; i != 100; i++) {
        mob->red.sprite[i] = create_sprite("./assets/mob/1/run.png", -30, -15);
        mob->green.sprite[i] = create_sprite
            ("./assets/mob/2/run.png", -30, -15);
        mob->black.sprite[i] = create_sprite
            ("./assets/mob/3/run.png", -100, -15);
        mob->grey.sprite[i] = create_sprite
            ("./assets/mob/4/run.png", -100, -15);
        sfSprite_setScale(mob->red.sprite[i], scl);
        sfSprite_setScale(mob->green.sprite[i], scl);
        sfSprite_setScale(mob->black.sprite[i], scl);
        sfSprite_setScale(mob->grey.sprite[i], scl);
        sfSprite_setTextureRect(mob->red.sprite[i], rect);
        sfSprite_setTextureRect(mob->green.sprite[i], rect);
        sfSprite_setTextureRect(mob->black.sprite[i], rect);
        sfSprite_setTextureRect(mob->grey.sprite[i], rect);
    }
}

void create_mymob_spr(mob_t *mob)
{
    sfVector2f scl = {0.4, 0.4};

    read_map_path(mob);
    mob->red.clock = sfClock_create();
    mob->green.clock = sfClock_create();
    mob->black.clock = sfClock_create();
    mob->grey.clock = sfClock_create();
    mob->red.sprite = malloc(sizeof(sfSprite *) * 100);
    mob->green.sprite = malloc(sizeof(sfSprite *) * 100);
    mob->black.sprite = malloc(sizeof(sfSprite *) * 100);
    mob->grey.sprite = malloc(sizeof(sfSprite *) * 100);
    create_mob_spr(mob, scl);
    create_gameplay_spr(mob);
    create_wave(mob);
}
