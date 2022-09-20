NAME = so_long

SRC = so_long.c

CFLAGS = -Wall -Wextra -Werror
CFLAGS += -Lmlx -lmlx -framework OpenGL -framework AppKit -lz

CC = cc

RM = rm -f

MLX_PATH = ./mlx/libmlx.a

$(NAME):	$(SRC) $(MLX_PATH)
				$(CC) $(CFLAGS) $(SRC) $(MLX_PATH) -o $(NAME)

$(MLX_PATH):
				make -C ./mms
				mv ./mms/libmlx.dylib .
				make -C ./mlx

all:	$(NAME)

clean:
		$(RM) $(NAME)
		make clean -C ./mlx
		make clean -C ./mms

fclean: clean
			$(RM) libmlx.dylib

re: fclean all

.PHONY: all clean fclean re
