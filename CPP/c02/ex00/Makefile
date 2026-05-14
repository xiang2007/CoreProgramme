CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -O3 -std=c++98
RM = rm -rf

SRC = main.cpp Fixed.cpp
HEADER = Fixed.hpp

NAME = Fixed

$(NAME):
	$(CPP) $(CPPFLAG) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re