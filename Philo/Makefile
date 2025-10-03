CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I./includes 
LIB = -L./utils -lutils
RM = rm -rf

SRC = ./parsing.c ./philo.c

NAME = philo

$(NAME):
	$(MAKE) -C utils
	$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	@$(MAKE) -C utils clean
	@echo "Clean complete!"

fclean:
	@$(MAKE) -C utils fclean
	@$(RM) $(NAME)
	@echo "deep clean complete!"

re: fclean all
