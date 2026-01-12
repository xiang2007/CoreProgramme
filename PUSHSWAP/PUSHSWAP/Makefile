# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 11:56:28 by selow             #+#    #+#              #
#    Updated: 2026/01/12 17:16:53 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft -g -pg
CC = cc
RM = rm -f

LIB_PATH = ./libft
LIBFT = $(LIB_PATH)/libft.a

SRC =	Push_swap.c \
	input_parsing/split_atoi.c \
	input_parsing/init_arr_atoi.c \
	input_parsing/stack_utils.c \
	input_parsing/init_stack.c \
	execution/operations/operations2.c \
	execution/operations/operations.c \
	execution/markup/quicksort.c \
	execution/markup/index_markup.c \
	execution/markup/markup_utils.c \
	execution/markup/max_markup.c \
	execution/sort_main2.c \
	execution/sort_main1.c \

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB_PATH)

test: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) libft/libft.a Push_swap.c init_stack.c stack_utils.c sort_three.c

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@
	
bonus: $(BONUSES:.c=.o)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIB_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_PATH) fclean

re: fclean all

.PHONY: re fclean bonus all clean
