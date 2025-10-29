# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
<<<<<<< HEAD
#    Created: 2025/10/23 21:05:39 by wshou-xi          #+#    #+#              #
#    Updated: 2025/10/23 21:08:31 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./includes
RM = rm -rf

PHISRC = ./main.c
=======
#    Created: 2025/10/22 10:07:57 by wshou-xi          #+#    #+#              #
#    Updated: 2025/10/29 22:22:19 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes
LIB = -lreadline -lhistory -Llibft -lft
RM = rm -rf

PHISRC = ./prompt.c ./utils.c ./main.c ./executing.c
>>>>>>> main

SRC = $(PHISRC)
OBJS = $(SRC:.c=.o)
NAME = minishell

<<<<<<< HEAD
$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
=======
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	@$(MAKE) -s -C libft
	@$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)
	@echo finished make
>>>>>>> main

all: $(NAME)

clean:
<<<<<<< HEAD
	$(RM) $(NAME)

fclean: clean
=======
	@$(RM) $(NAME)
	@$(MAKE) -s -C libft clean
	@echo finished cleaning

fclean: clean
	@$(MAKE) -s -C libft fclean
	@echo finished fclean
>>>>>>> main

re: fclean all

.PHONY: all clean fclean re