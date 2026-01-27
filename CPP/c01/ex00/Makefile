# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 19:22:41 by wshou-xi          #+#    #+#              #
#    Updated: 2026/01/12 21:26:20 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++
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