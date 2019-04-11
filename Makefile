##
## EPITECH PROJECT, 2018
## my_runner
## File description:
## Makefile
##

SRC	=	src/defender.c	\
		src/annex_ini_all.c	\
		src/annex_gameplay.c	\
		src/window.c	\
		src/mouse/mouse.c	\
		src/menu/menu.c	\
		src/menu/menu_play.c	\
		src/menu/shop.c	\
		src/menu/story.c	\
		src/menu/option.c	\
		src/menu/htp.c	\
		src/menu/end_menu.c	\
		src/menu/cond_menu.c	\
		src/button/act_menu_button.c	\
		src/button/act_option_button.c	\
		src/button/annex_act_option_button.c	\
		src/button/annex_act_menu_button.c	\
		src/button/act_play_button.c	\
		src/button/annex_act_play_button.c	\
		src/button/annex_sec_act_menu_button.c	\
		src/button/act_pause_button.c	\
		src/button/annex_act_pause_button.c	\
		src/button/annex_sec_act_pause_button.c	\
		src/button/act_confirm_menu.c	\
		src/button/annex_act_confirm_menu.c	\
		src/button/button_how_to_play.c	\
		src/menu/confirm_menu.c	\
		src/createsprites.c	\
		src/button/init_button.c	\
		src/button/annex_init_button.c	\
		src/init_all.c	\
		src/sound/sound.c	\
                src/sound/sound_modifer.c       \
		src/gameplay.c	\
		src/menu/pause.c	\
                src/caracters/wave.c    \
                src/caracters/tower_condi.c    \
                src/caracters/send_projectile.c    \
                src/caracters/redmob.c  \
                src/caracters/init_life_mob.c  \
                src/caracters/life.c  \
                src/caracters/attack.c  \
                src/caracters/move_on_map.c  \
                src/caracters/anime_mob.c  \
                src/caracters/mob.c     \
                src/caracters/my_strcpy.c       \
		src/caracters/clock_mob.c	\
		src/caracters/annex_proj.c	\
		src/caracters/annex_sec_proj.c	\
		src/caracters/condi_towers.c	\
		src/caracters/cond_wave.c	\
		src/menu/option_pause.c	\
		src/tower/ini_towers.c	\
		src/tower/build_tower.c	\
		src/tower/projectiles.c	\
		src/tower/annex_build_tower.c	\
		src/tower/for_forest.c	\
		src/tower/whose_map.c	\
		src/tower/check_upgrade.c	\
		src/tower/unpop_menu.c	\
		src/tower/upgrade.c	\
		src/tower/annex_for_tower.c	\
                src/spell/ini_spell.c   \
                src/spell/dmg_spell.c  \
                src/spell/throw_spell.c \
                src/spell/disp_spell.c  \
                src/spell/cooldown.c    \
		src/spell/cond_dmg_spell.c	\
                src/loading.c   \
		src/destroy_all.c	\
		src/main.c	\

OBJ	=	$(SRC:.c=.o)

LIB	=	-L./lib/my -lmy

CSFML	=	-lcsfml-audio -lcsfml-window -lcsfml-system -lcsfml-graphics

CPPFLAGS	=	-I./include/ -Wall -Wextra -g3

NAME	=	my_defender

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my && make
	gcc -o $(NAME) $(OBJ) $(CSFML) $(LIB) $(CPPFLAGS)

clean:
	cd lib/my && make clean
	rm -f $(OBJ)
	cd src/ && rm -f $(OBJ)

fclean: clean
	cd lib/my && make fclean
	rm -f $(NAME)
	cd src/ && rm -f $(OBJ)

re:	fclean all

.PHONY: all clean fclean re
