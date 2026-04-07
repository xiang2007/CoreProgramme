CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

SRC = main.cpp

NAME = sed

$(NAME):
	$(CPP) $(CPPFLAG) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re