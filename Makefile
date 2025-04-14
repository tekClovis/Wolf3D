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

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -g -Iinclude

LDFLAG = -lcsfml-graphics -lcsfml-system -lcsfml-audio \
	-lcsfml-window -lm -lncurses

all: $(NAME)
$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAG)
	rm -rf $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
