/*
** EPITECH PROJECT, 2019
** window
** File description:
** struct for windows
*/

typedef struct menu_button
{
    sfSprite *play_s;
    sfIntRect rect_play;
    sfSprite *shop_s;
    sfIntRect rect_shop;
    sfSprite *story_s;
    sfIntRect rect_story;
    sfSprite *leave_s;
    sfIntRect rect_leave;
    sfVector2f pos_leave;
    sfSprite *return_s;
    sfIntRect rect_return;
    sfVector2f pos_return;
    sfSprite *option_s;
    sfIntRect rect_option;
    sfVector2f pos_option;
} mbutton_t;

typedef struct play_button
{
    int change_bck;
    sfSprite *easy_s;
    sfIntRect rect_easy;
    sfSprite *medium_s;
    sfIntRect rect_medium;
    sfSprite *hard_s;
    sfIntRect rect_hard;
    sfSprite *hell_s;
    sfIntRect rect_hell;
    sfSprite *htp_s;
    sfIntRect rect_htp;
} pbutton_t;

typedef struct mouse
{
    int which_mouse;
    sfVector2i mouse_pos;
    sfVector2f pos;
    sfSprite *mouse_s;
    sfSprite *sec_mouse_s;
} mouse_t;

typedef struct sound
{
    int wich_music;
    sfMusic *menu;
    sfMusic *desert;
    sfMusic *forest;
    sfMusic *snow;
    sfMusic *hell;
    sfMusic *epic;
    sfMusic *epic1;
    sfMusic *epic3;
    sfMusic *storm;
    sfMusic *freeze;
    sfMusic *acid;
    sfMusic *click;
    sfMusic *arrow;
    sfMusic *elec;
    sfMusic *rock;
} sound_t;

typedef struct play_background
{
    sfSprite *forest_s;
    sfSprite *desert_s;
    sfSprite *mountain_s;
    sfSprite *hell_s;
} pbck_t;

typedef struct htp
{
    sfSprite *htp_s;
    sfIntRect rect_htp;
    sfClock *clock;
    sfTime time;
    float sec;
} htp_t;

typedef struct menu_shop
{
    sfSprite *shop_s;
} shop_t;

typedef struct story
{
    sfSprite *story_s;
} story_t;

typedef struct option
{
    int volume;
    sfSprite *board_s;
    sfSprite *music_button_s;
    sfIntRect rect_music_button;
    sfSprite *music_bar_s;
    sfIntRect rect_music_bar;
    sfSprite *select_fmouse_s;
    sfSprite *select_smouse_s;
} option_t;

typedef struct pause
{
    int pause;
    sfSprite *pause_s;
    sfSprite *resume_s;
    sfIntRect rect_resume;
    sfSprite *music_s;
    sfIntRect rect_music;
    sfSprite *menu_s;
    sfIntRect rect_menu;
    sfVector2f pos_menu;
} pause_t;

typedef struct clock_game
{
    sfClock **clock;
    sfTime *time;
    float *sec;
} clock_game_t;

typedef struct end
{
    sfSprite *victory;
    sfSprite *defeate;
    int is_reini;
} end_t;

typedef struct window
{
    short is_open;
    sfClock *clock;
    sfTime time;
    float sec;
    sfSprite *loading;
    sfRenderWindow *window;
    sfEvent event;
    sfSprite *menu_s;
    mbutton_t mbutton;
    pbutton_t pbutton;
    pbck_t pbck;
    mouse_t mouse;
    shop_t shop;
    clock_game_t cgame;
    story_t story;
    sound_t sound;
    option_t option;
    pause_t pause;
    htp_t htp;
    end_t end;
} dwd_t;
