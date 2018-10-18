# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 14:21:58 by amedvedi          #+#    #+#              #
#    Updated: 2018/09/27 14:22:00 by amedvedi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_strcat.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strstr.c ft_strlcat.c ft_memset.c \
ft_bzero.c ft_memcpy.c ft_memmove.c ft_memccpy.c ft_strchr.c ft_memchr.c ft_memcmp.c ft_strrchr.c ft_strnstr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_putchar.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putendl_fd.c ft_putendl.c \
ft_putstr.c ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_itoa_base.c ft_str_is_num.c ft_str_is_alpha.c ft_find_next_prime.c \
ft_isprime.c ft_str_digit.c ft_countunbr.c ft_countnbr.c ft_itoabase_r.c ft_putnstr.c

.NOTPARALLEL: all clean fclean re

SRC_O = $(SRC:.c=.o)
all: $(NAME)

$(NAME): 
	gcc -c -Wall -Wextra -Werror $(SRC)
	@ar rc $(NAME) $(SRC_O)
	@ranlib $(NAME)
clean:
	@/bin/rm -f $(SRC_O)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
