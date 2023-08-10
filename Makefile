NAME = so_long
SRC = main.c checkers.c utils.c mapread.c mapread_utils.c
OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -I$(GNL)/get_next_line.h -I$(MINILIBX)/mlx.h -g
GNL = gnl
MINILIBX = minilibx

all: $(NAME)

$(NAME): $(OBJ)
	@make -s -C $(GNL)
	@make -s -C $(MINILIBX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(GNL)/libget_next_line.a $(MINILIBX)/libmlx.a -g

clean:
	@$(RM) $(OBJ)
	@make clean -s -C $(GNL)
	@make clean -s -C $(MINILIBX)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -s -C $(GNL)

re: fclean all

.PHONY: all clean fclean re
