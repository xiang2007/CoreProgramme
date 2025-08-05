CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./includes
AR = ar rcs
RM = rm -rf
SRC = ./Utils1.c ./Utils2.c ./push_swap.c ./checking.c ./asign_nodes.c ./put_instruction.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(MO)
	$(MVO)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all c
 
c:
	$(CC) $(CFLAGS) $(SRC) -o push_swap

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) OBJS

all: $(NAME)

re: fclean all
