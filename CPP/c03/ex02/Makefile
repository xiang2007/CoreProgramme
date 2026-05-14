CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -O3 -std=c++98
RM = rm -rf

SRC = ClapTrap.cpp main.cpp FragTrap.cpp
HEADER = FragTrap.hpp ClapTrap.hpp

NAME = FragTrap

$(NAME):
	$(CPP) $(CPPFLAG) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re