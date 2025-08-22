CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./includes
AR = ar rcs
RM = rm -rf
SRC =	./pipex.c ./Utils1.c ./getpath.c ./check_permission.c
PRINTF_SRC = ./ft_printf/ft_printf.c ./ft_printf/ft_signs.c \
			./ft_printf/ft_utils2.c ./ft_printf/ft_utils1.c \
			./ft_printf/ft_utils3.c \

OBJS = $(SRC:.c=.o)
NAME = pipex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(PRINTF_SRC) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
