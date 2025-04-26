##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## .
##

NAME = wolf3d


SRC += main.c
SRC += src/map.c
SRC += src/wolf3d.c
SRC += src/init/create_window.c
SRC += src/check/is_wall.c
SRC += src/game/move_player.c
SRC += src/game/launch_game.c
SRC += src/game/choose_window_mode.c
SRC += src/game/map/display_full_map.c
SRC += src/init/init_game_handler.c
SRC += src/init/init_player_ennemies.c
SRC += src/game/3d/display_3d_map.c
SRC += src/game/free_game.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Iinclude -Llib/ -lmy

LDFLAG = -g -lcsfml-graphics \
 		-lcsfml-system -lcsfml-audio \
		-lcsfml-window -lm -lncurses -g \

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./lib/
		gcc -g $(OBJ) $(CFLAGS) -o $(NAME)  $(LDFLAG)

clean:
		make clean -C ./lib/
		rm -rf $(OBJ)

fclean: clean
		make fclean -C ./lib/
		rm -rf $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: fclean all
