# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 14:34:05 by amedvedi          #+#    #+#              #
#    Updated: 2018/09/27 14:34:06 by amedvedi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = treat_c_conv.c\
	treat_d_conv.c\
	treat_o_conv.c\
	treat_u_conv.c\
	treat_p_conv.c\
	treat_no_conv.c\
	ft_printf.c\
	assign_conv.c\
	format_du.c\
	fill_env.c\
	treat_s_conv.c\
	treat_ss_conv.c\
	unicode_conv.c\
	treat_x_conv.c

NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror

LIBDIR = ..



LIBFT = $(LIBDIR)/libft.a

_DEPS = libftprintf.h

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re
.NOTPARALLEL: all clean fclean re

all: $(NAME)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<

$(NAME): $(LIBFT) $(OBJ)
			cp ../libft.a ./$(NAME)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

$(LIBFT):
	make -C $(LIBDIR)

clean:
	/bin/rm -rf *.o
	make clean -C $(LIBDIR)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -rf libft/libft.a

re : fclean all
