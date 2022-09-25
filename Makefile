NAME = so_long

SRC = so_long.c

OBJ			= $(SRC:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -Lmlx -lmlx -framework OpenGL -framework AppKit -lz

CC = cc

RM = rm -f

MLX = ./mlx/libmlx.a

MLX_LINUX = ./mlx_linux/libmlx.a

INCLUDE_L= -L ./mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(NAME):	$(SRC) $(MLX_PATH)
				$(CC) $(CFLAGS) $(SRC) $(MLX_PATH) -o $(NAME)

linux:		$(SRC) $(MLX_LINUX)
				$(CC) $(CFLAGS) $(SRC) $(INCLUDE_L) -o $(NAME)

$(MLX_PATH):
				make -C ./mlx

$(MLX_LINUX):
		make -C ./mlx_linux

all:	$(NAME)

clean:
		$(RM) $(NAME)
		make clean -C ./mlx

fclean: clean
			$(RM) libmlx.dylib

re: fclean all

.PHONY: all clean fclean re
