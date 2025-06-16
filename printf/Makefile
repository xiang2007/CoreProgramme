CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

SRC = $(shell find -name "*.c")
OBJ = $(SRC:.c=.o)
NAME = a.out
AFILE = libft.a

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(AFILE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all cc

clean:
	$(RM) $(NAME)

fclean:	clean

all: $(NAME)

re: fclean all