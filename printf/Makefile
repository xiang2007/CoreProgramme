CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./include
AR = ar rcs
RM = rm -f

SRC = ./ft_utils1.c ./ft_utils2.c ./ft_printf.c ./ft_signs.c ./ft_utils3.c ./main.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all c
clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

all: $(NAME)
	$(AR) $(NAME) $(OBJ)

re: fclean all

c:
	$(CC) $(CFLAGS) $(SRC)