NAME = so_long

SRC = so_long.c\
	  utils.c

OBJ			= $(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

CFLAGS = -Wall -Wextra -Werror

INCLUDE_M = -Lmlx -lmlx -framework OpenGL -framework AppKit

INCLUDE_L= -L ./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CC = cc

RM = rm -f

LIBFT = ./libft/libft.a

MLX = ./mlx/libmlx.a

MLX_LINUX = ./mlx_linux/libmlx.a


$(NAME):	$(SRC) $(MLX) $(LIBFT)
				$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(INCLUDE_M) -o $(NAME)

linux:		$(SRC) $(MLX_LINUX) $(LIBFT)
				$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(INCLUDE_L) -o $(NAME)

$(LIBFT):
			make -C ./libft

$(MLX):
			make -C ./mlx

$(MLX_LINUX):
		make -C ./mlx_linux

all:	$(NAME)

clean:
		$(RM) $(NAME)
		make clean -C ./mlx
		make clean -C ./libft

fclean: clean
		$(RM) $(NAME)
		make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
