CC = cc
RM = rm -rf
SRC = ./ft_split.c ./sudoku.c ./asign_block.c

NAME = sudoku

$(NAME):
	$(CC) $(SRC) -o $(NAME)

.PHONY: clean re

all: $(NAME)

clean:
	$(RM) $(NAME)

re: clean all
	