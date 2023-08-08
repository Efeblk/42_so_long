NAME = so_long
SRC = main.c checkers.c utils.c
OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -I$(GNL)/get_next_line.h
GNL = gnl

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(GNL)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(GNL)/libget_next_line.a

clean:
	@$(RM) $(OBJ)
	@make clean -s -C $(GNL)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -s -C $(GNL)

re: fclean all

.PHONY: all clean fclean re
