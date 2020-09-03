##
## EPITECH PROJECT, 2019
## CPool_evalexpr_2019
## File description:
## Makefile
##

SRC	=	src/map/get_map_name.c 				\
		src/map/create_map.c 				\
		src/map/display_map.c 				\
		src/map/map_event.c 				\
		src/map/map_event_move.c 			\
		src/map/mem_map.c 					\
		src/map/image/create_image.c 		\
		src/particle_engine/particle.c 		\
		src/particle_engine/rain.c 			\
		src/particle_engine/smoke.c 		\
		src/particle_engine/effect_creator.c\
		src/particle_engine/load_effect.c 	\
		src/player/update_player.c 			\
		src/player/update_player_battle.c 	\
		src/player/update_player_inventory.c\
		src/player/update_player_quest.c 	\
		src/player/hitbox_map_bg.c 			\
		src/player/hitbox_map_mg.c 			\
		src/player/hitbox_map_fg.c 			\
		src/player/map_border.c 			\
		src/player/display_player.c 		\
		src/player/inventory/fill_inventory.c\
		src/player/inventory/fill_inventory_pos.c\
		src/player/inventory/movin_inventory.c\
		src/player/inventory/searching_case.c\
		src/player/inventory/searching_uncase.c\
		src/player/inventory/switching_case.c\
		src/player/inventory/switching_case2.c\
		src/player/load_player.c 			\
		src/player/load_player_set.c 		\
		src/player/set_player_var.c 		\
		src/player/set_player_var_two.c 	\
		src/player/set_player_var_three.c 	\
		src/npc/load_npc.c 					\
		src/npc/load_npc2.c 				\
		src/npc/set_npc_var.c 				\
		src/npc/set_npc_var2.c 				\
		src/npc/set_npc_var3.c 				\
		src/npc/set_npc_var4.c 				\
		src/npc/set_npc_stat.c 				\
		src/npc/set_npc_stat2.c 			\
		src/npc/set_npc_stat3.c 			\
		src/npc/display_npc.c 				\
		src/npc/display_npc2.c 				\
		src/props/load_props.c 				\
		src/props/set_props_var.c 			\
		src/props/display_props.c 			\
		src/items/load_items.c 				\
		src/items/set_item_var.c 			\
		src/items/set_item_var_two.c 		\
		src/items/load_weapons.c 			\
		src/items/load_weapons_pointer.c 	\
		src/items/set_weapon_var.c 			\
		src/items/set_weapon_var_two.c 		\
		src/items/set_weapon_var_three.c 	\
		src/items/set_weapon_var_four.c 	\
		src/items/copy_object.c 			\
		src/light_manager/load_light.c 		\
		src/light_manager/set_light_var.c 	\
		src/light_manager/set_light_var_2.c \
		src/light_manager/display_lights.c 	\
		src/redirection/redirect.c 			\
		src/redirection/load_redirect.c 	\
		src/redirection/set_redirect_var_two.c \
		src/redirection/set_redirect_var.c 	\
		src/fight/fight.c 					\
		src/fight/player_fight.c 			\
		src/fight/npc_fight.c 				\
		src/fight/event_fight.c 			\
		src/fight/display_fight.c 			\
		src/fight/check_fight_condition.c	\
		src/fight/npc_fight_shot.c			\
		src/fight/player_fight_shot.c		\
		src/utils/math.c 					\
		src/utils/get_str.c 				\
		src/utils/get_str2.c 				\
		src/utils/shape_make.c 				\
		src/utils/malloc_error.c 			\
		src/utils/free_list.c 				\
		src/utils/display.c 				\
		src/menu/breakt.c 					\
		src/menu/game_over.c 				\
		src/menu/to_be_continued.c 			\
		src/menu/help.c 					\
		src/menu/load.c						\
		src/menu/menu.c 					\
		src/menu/settings.c 				\
		src/save_system/save.c 				\
		src/save_system/save_2.c 			\
		src/save_system/save_3.c 			\
		src/save_system/save_4.c 			\
		src/inits/b_init.c 					\
		src/inits/game_init.c 				\
		src/inits/game_init_sound.c 		\
		src/inits/load_current_map.c 		\
		src/inits/init_quests.c 			\
		src/inits/first_anim.c 				\
		src/inits/button_animations.c 		\
		src/event/event_menu.c 				\
		src/event/event_settings.c 			\
		src/event/event.c 					\
		src/event/event2.c 					\
		src/main.c

NAME	= 	my_rpg

INCLUDE_PATH = ./include

LIB_PATH = ./lib

all:	$(NAME)

$(NAME):
	cd lib/my && make re
	gcc $(SRC) -o $(NAME) -L$(LIB_PATH) -I$(INCLUDE_PATH) -lmy -lcsfml-graphics -lcsfml-system -lm -lcsfml-window -lcsfml-audio

clean:
	rm -rf $(NAME)

fclean:		clean
	rm -rf $(NAME)

re: fclean $(NAME)