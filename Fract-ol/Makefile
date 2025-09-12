# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 16:18:33 by wshou-xi          #+#    #+#              #
#    Updated: 2025/09/13 00:49:12 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I./includes
LIB = -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM = rm -rf

SRC = ./mandelbrot.c ./arithmetic.c ./utils1.c ./fractol.c ./julia.c
LIBFT_SRC = ./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_memset.c ./libft/ft_putchar_fd.c ./libft/ft_strlen.c \
		./libft/ft_strnstr.c ./libft/ft_strrchr.c ./libft/ft_substr.c ./libft/ft_tolower.c ./libft/ft_toupper.c \
	./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c ./libft/ft_putstr_fd.c ./libft/ft_split.c ./libft/ft_strchr.c \
	./libft/ft_strdup.c ./libft/ft_striteri.c ./libft/ft_strjoin.c ./libft/ft_strlcat.c ./libft/ft_strlcpy.c \
	./libft/ft_strmapi.c ./libft/ft_strncmp.c ./libft/ft_strtrim.c ./libft/ft_lstlast.c ./libft/ft_memcmp.c \
	./libft/ft_atoi.c ./libft/ft_bzero.c ./libft/ft_calloc.c ./libft/ft_isalnum.c ./libft/ft_isalpha.c \
	./libft/ft_isascii.c ./libft/ft_isdigit.c ./libft/ft_isprint.c ./libft/ft_itoa.c ./libft/ft_memchr.c \

NAME = fractol

.PHONY: c clean fclean re

c:
	$(CC) $(CFLAGS) $(LIBFT_SRC) $(SRC) $(LIB) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean c
