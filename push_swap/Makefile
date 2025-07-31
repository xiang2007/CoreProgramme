CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./include
AR = ar rcs
RM = rm -rf
SRC = 
OBJ = $(SRC:.c=.o)
NAME = push_swap

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

all: $(NAME)

re: fclean all
