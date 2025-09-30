# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/16 20:16:49 by aaissa            #+#    #+#              #
#    Updated: 2025/09/30 17:22:11 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := philo
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -Iincludes
OBJDIR  := obj
SRCDIR  := src
SRCS    := main.c initializer.c routine.c utils.c monitor.c check_args.c mutex_utils.c
OBJS    := $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lpthread

# Compile .o files from src/ into obj/
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rprintf("size of hi is %d\n", ft_strlen("hi"));m -f $(NAME)

re: fclean all
