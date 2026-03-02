CPP = c++
CPPFLAG = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

FILES = phonebook_utils.cpp Phonebook.cpp Contact.cpp main.cpp
HEADER = Phonebook.hpp Contact.hpp

SRC = $(FILES)
NAME = phonebook

$(NAME):
	$(CPP) $(CPPFLAG) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all re clean fclean