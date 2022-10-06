NAME = 			so_long

SRC = 			so_long.c\
				utils.c\
				map_valid.c\
				map_valid_utils.c\
				map_manage.c\
				map_manage_utils.c\
				player_move.c\
				exit_funcs.c

OBJ			= 	$(SRC:.c=.o)

%.o: %.c
				$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

CFLAGS = 		-Wall -Wextra -Werror

INCLUDE_M = 	-Lmlx -lmlx -framework OpenGL -framework AppKit

CC = 			cc

RM = 			rm -f

LIBFT = 		./libft/libft.a

MLX = 			./mlx/libmlx.a

$(NAME):		$(SRC) $(MLX) $(LIBFT)
					$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(INCLUDE_M) -o $(NAME)

$(LIBFT):
				make -C ./libft

$(MLX):
				make -C ./mlx

all:			$(NAME)

clean:
				make clean -C ./mlx
				make clean -C ./libft

fclean:			clean
				$(RM) $(NAME)
				make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
