NAME		= libft.a

SRC			= ft_isalnum.c\
			  ft_isprint.c\
			  ft_memcpy.c\
			  ft_putendl_fd.c\
			  ft_strchr.c\
			  ft_strlcat.c\
			  ft_strncmp.c\
			  ft_substr.c\
			  ft_atoi.c\
			  ft_isalpha.c\
			  ft_itoa.c\
			  ft_memmove.c\
			  ft_putnbr_fd.c\
			  ft_strdup.c\
			  ft_strlcpy.c\
			  ft_strnstr.c\
			  ft_tolower.c\
			  ft_bzero.c\
			  ft_isascii.c\
			  ft_memchr.c\
			  ft_memset.c\
			  ft_putstr_fd.c\
			  ft_striteri.c\
			  ft_strlen.c\
			  ft_strrchr.c\
			  ft_toupper.c\
			  ft_calloc.c\
			  ft_isdigit.c\
			  ft_memcmp.c\
			  ft_putchar_fd.c\
			  ft_split.c\
			  ft_strjoin.c\
			  ft_strmapi.c\
			  ft_strtrim.c\
			  ft_printf.c\
			  ft_putchar_print.c\
			  ft_putstr_print.c\
			  ft_putnbr_print.c\
			  ft_putunbr_print.c\
			  ft_hex_print.c\
			  ft_pointeraddress_print.c\
			  get_next_line.c\
			  get_next_line_utils.c


SRC_B		= ft_lstnew_bonus.c\
			  ft_lstadd_front_bonus.c\
			  ft_lstsize_bonus.c\
			  ft_lstadd_back_bonus.c\
			  ft_lstlast_bonus.c\
			  ft_lstdelone_bonus.c\
			  ft_lstclear_bonus.c\
			  ft_lstiter_bonus.c\
			  ft_lstmap_bonus.c


OBJ_B			= $(SRC_B:.c=.o)

OBJ			= $(SRC:.c=.o)

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) -c $(SRC)
				@ar rcs $(NAME) $(OBJ)

all:		$(NAME)

bonus:		$(OBJ_B)
			@$(CC) $(CFLAGS) -c $(SRC_B)
				@ar rcs $(NAME) $(OBJ_B)


clean:
			@$(RM) $(OBJ)
			@$(RM) $(OBJ_B)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
