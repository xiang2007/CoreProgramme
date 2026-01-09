CPP = c++
CPPFLAG = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

FILES = phonebook_utils.cpp phonebook.cpp
HEADER = Phonebook.hpp Contact.hpp

SRC = $(FILES)
OBJS = $(SRC:.cpp=.o)
NAME = Phonebook

%.o %.cpp:
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME):
	$(CPP) $(CPPFLAG) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all re clean fclean