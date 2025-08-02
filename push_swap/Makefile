CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./includes
AR = ar rcs
RM = rm -rf
MO = mkdir OBJS
MVO = mv $(OBJ) OBJS
SRC = ./Utils1.c ./Utils2.c ./push_swap.c ./checking.c ./asign_nodes.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(MO)
	$(MVO)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) OBJS

all: $(NAME)

re: fclean all
