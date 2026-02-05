CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
HEADER = Zombie.h

NAME = program

$(NAME):
	$(CPP) $(CPPFLAG) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re