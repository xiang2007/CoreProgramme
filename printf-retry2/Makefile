CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./include
AR = ar rcs
RM = rm -rf
MD = mkdir
OBJF = OBJFILE
SRC = ./ft_utils1.c ./ft_utils2.c ./ft_printf.c ./ft_signs.c ./ft_utils3.c
MV = mv ./ft_utils1.o ./ft_utils2.o ./ft_printf.o ./ft_signs.o ./ft_utils3.o
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(MD) $(OBJF)
	$(MV) $(OBJF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all
clean:
	$(RM) $(OBJF)

fclean:	clean
	$(RM) $(NAME)

all: $(NAME)

re: fclean all
