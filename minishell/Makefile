# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 10:07:57 by wshou-xi          #+#    #+#              #
#    Updated: 2025/10/28 17:32:58 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes
LIB = -lreadline -lhistory
RM = rm -rf

PHISRC = ./prompt.c ./utils.c ./main.c

SRC = $(PHISRC)
OBJS = $(SRC:.c=.o)
NAME = minishell

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re