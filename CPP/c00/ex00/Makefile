CPP = c++
CPPFLAG = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

FILES = megaphone.cpp

SRC = $(FILES)

NAME = megaphone

$(NAME):
	$(CPP) $(CPPFLAG) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all re clean fclean