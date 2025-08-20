CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./includes
AR = ar rcs
RM = rm -rf
SRC =	./Utils1.c ./Utils2.c ./push_swap.c ./checking.c ./push.c ./Utils3.c\
		./rotate.c ./reverse_rotate.c ./swapping.c ./asign_stack.c ./sorting.c \
		./selection_sort.c ./quicksort.c ./error.c ./rs.c \
		./checkone.c ./ft_isdigit.c

NAME = push_swap

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
