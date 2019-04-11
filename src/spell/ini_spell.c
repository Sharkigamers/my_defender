/*
** EPITECH PROJECT, 2019
** defender
** File description:
** spell
*/

#include "my.h"

void disp_spell(mob_t *mob, dwd_t *dwd)
{
    sfRenderWindow_drawSprite(dwd->window, mob->spell.icon1, NULL);
    sfRenderWindow_drawSprite(dwd->window, mob->spell.icon2, NULL);
    sfRenderWindow_drawSprite(dwd->window, mob->spell.icon3, NULL);
}

void rect_spell(mob_t *mob, sfVector2f scl)
{
    sfSprite_setScale(mob->spell.icon1, scl);
    sfSprite_setScale(mob->spell.icon2, scl);
    sfSprite_setScale(mob->spell.icon3, scl);
    mob->spell.rect_spell1.left = 92;
    mob->spell.rect_spell1.top = 750;
    mob->spell.rect_spell1.height = 137;
    mob->spell.rect_spell1.width = 128;
    mob->spell.rect_spell2.left = 356;
    mob->spell.rect_spell2.top = 684;
    mob->spell.rect_spell2.height = 219;
    mob->spell.rect_spell2.width = 169;
    mob->spell.rect_spell3.left = 610;
    mob->spell.rect_spell3.top = 790;
    mob->spell.rect_spell3.height = 126;
    mob->spell.rect_spell3.width = 160;
    sfSprite_setTextureRect(mob->spell.spell1_s, mob->spell.rect_spell1);
    sfSprite_setTextureRect(mob->spell.spell2_s, mob->spell.rect_spell2);
    sfSprite_setTextureRect(mob->spell.spell3_s, mob->spell.rect_spell3);
}

void annex_spell(mob_t *mob)
{
    mob->spell.is_click = malloc(sizeof(int) * 6);
    mob->spell.clock = malloc(sizeof(sfClock *) * 3);
    mob->spell.time = malloc(sizeof(sfTime) * 3);
    mob->spell.sec = malloc(sizeof(float) * 3);
    for (int i = 0; i < 3; i++) {
        mob->spell.is_click[i] = 0;
        mob->spell.clock[i] = sfClock_create();
    }
    for (int i = 3; i < 6; i++)
        mob->spell.is_click[i] = 1;
}

void ini_spell(mob_t *mob)
{
    sfIntRect rect = {800, 720, 214, 214};
    sfVector2f scl;

    scl.x = 0.5;
    scl.y = 0.5;
    mob->spell.spell1_s = create_sprite("assets/gameplay/spell_dc.png", 0, 0);
    mob->spell.spell2_s = create_sprite("assets/gameplay/spell_dc.png", 0, 0);
    mob->spell.spell3_s = create_sprite("assets/gameplay/spell_dc.png", 0, 0);
    mob->spell.icon1 = create_sprite("assets/gameplay/spell_dc.png", 700, 900);
    mob->spell.icon2 = create_sprite("assets/gameplay/spell_dc.png", 900, 900);
    mob->spell.icon3 = create_sprite("assets/gameplay/spell_dc.png", 1100, 900);
    sfSprite_setTextureRect(mob->spell.icon1, rect);
    rect.left += 215;
    sfSprite_setTextureRect(mob->spell.icon2, rect);
    rect.left += 215;
    sfSprite_setTextureRect(mob->spell.icon3, rect);
    rect_spell(mob, scl);
    annex_spell(mob);
}
