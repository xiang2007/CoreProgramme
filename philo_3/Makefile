# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/18 14:21:16 by wshou-xi          #+#    #+#              #
#    Updated: 2025/10/18 15:14:37 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -pthread -I./includes
RM = rm -rf

PHISRC = ./initialize.c ./main.c ./mutex_utils.c ./operations.c ./start_threads.c ./Utils.c

SRC = $(PHISRC)
OBJS = $(SRC:.c=.o)
NAME = philo

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
