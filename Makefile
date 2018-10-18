# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 14:19:06 by amedvedi          #+#    #+#              #
#    Updated: 2018/09/27 14:19:08 by amedvedi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
	path_parse.c \
	place_ants.c \
	room_validation.c \
	error.c \
	lem_del.c \
	explore_way.c \
	ft_linkdup.c \
	validate_room_and_cmd.c \
	new_room_maker.c \
	libft/get_next_line.c 

NAME = lem-in

CC = gcc -Wall -Wextra -Werror

LIBDIR = ./libft
PF_DIR = ./libft/ft_printf


LIBFT = $(LIBDIR)/libft.a

_DEPS = lemin.h

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re
.NOTPARALLEL: all clean fclean re

all: $(NAME)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<


$(NAME): $(LIBFT) $(OBJ)
			cp libft/libft.a ./
			cp libft/ft_printf/libftprintf.a ./
			$(CC) -o $(NAME) $(OBJ) libft.a libftprintf.a

$(LIBFT):
	make -C $(LIBDIR)
	make -C $(PF_DIR)

clean:
	/bin/rm -rf *.o
	make clean -C $(LIBDIR)
	make clean -C $(PF_DIR)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -rf libft/libft.a
	/bin/rm -rf libft.a
	/bin/rm -rf libft/ft_printf/libftprintf.a
	/bin/rm -rf libftprintf.a

re : fclean all
