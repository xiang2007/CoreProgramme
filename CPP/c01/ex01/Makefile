# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 19:24:09 by wshou-xi          #+#    #+#              #
#    Updated: 2026/01/14 11:59:06 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

SRC = main.cpp Zombie.cpp zombieHoard.cpp
HEADER = Zombie.h

NAME = zombie

$(NAME):
	$(CPP) $(CPPFLAG) $(SRC) $(HEADER) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re