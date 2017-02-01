# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anieto <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/27 15:13:40 by anieto            #+#    #+#              #
#    Updated: 2017/01/09 22:02:47 by wdebs            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = gcc
CFLAGS = -Wall -Wextra -Werror

NAME   = fillit
SRCS   = fillit_check.c solve_tet.c solve_things.c main.c
OBJS   = fillit_check.o solve_tet.o solve_things.o main.o
HEAD   = fillit.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -I$(HEAD) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
