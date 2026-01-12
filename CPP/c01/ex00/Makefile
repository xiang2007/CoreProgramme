CPP = c++ -g -pg
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

SRC = main.cpp Zombie.cpp randomChump.cpp newZombie.cpp
HEADER = Zombie.hpp

NAME = zombie

$(NAME):
	$(CPP) $(CPPFLAG) $(SRC) $(HEADER) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re