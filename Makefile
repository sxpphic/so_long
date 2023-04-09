NAME = so_long

SRC = 			so_long.c\
				map_valid.c\
				map_valid_utils.c\
				map_valid_utils2.c\
				map_manage.c\
				map_manage_utils.c\
				player_move.c\
				exit_funcs.c

OBJ			= $(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

CFLAGS = -Wall -Wextra -Werror

CC = cc

RM = rm -f

LIBFT = ./libft/libft.a

ifeq ($(shell uname -s), Darwin)
	INCLUDES	= -framework OpenGL -framework AppKit
	MLX 		= ./mlx/libmlx.a
	MLX_FOLDER	= ./mlx
else
	INCLUDES	= -L ./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	MLX		 = ./mlx_linux/libmlx.a
	MLX_FOLDER	= ./mlx_linux
endif

$(NAME):		$(SRC) $(MLX) $(LIBFT)
				$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(INCLUDES) -o $(NAME)


$(LIBFT):
			make -C ./libft

$(MLX):
			make -C $(MLX_FOLDER)

all:	$(NAME)

clean:
		$(RM) $(NAME)
		make clean -C $(MLX_FOLDER)
		make clean -C ./libft

fclean: clean
		$(RM) $(NAME)
		make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
