# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 10:07:57 by wshou-xi          #+#    #+#              #
#    Updated: 2025/10/29 16:31:33 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes
LIB = -lreadline -lhistory -Llibft -lft
RM = rm -rf

PHISRC = ./prompt.c ./utils.c ./main.c ./executing.c

SRC = $(PHISRC)
OBJS = $(SRC:.c=.o)
NAME = minishell

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	@$(MAKE) -s -C libft
	@$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)
	@echo finished make

all: $(NAME)

clean:
	@$(RM) $(NAME)
	@$(MAKE) -s -C libft clean
	@echo finished cleaning

fclean: clean
	@$(MAKE) -s -C libft fclean
	@echo finished fclean!!

re: fclean all

.PHONY: all clean fclean re