# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 17:20:50 by mkravetz          #+#    #+#              #
#    Updated: 2020/02/26 22:30:32 by jherrald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

LIBFT_P = libft/

SRC = ft_printf.c parser_spec.c convers_d.c parser.c utils.c utils_d.c \
	  convers_u.c utils_u.c\


OBJ = $(SRC:.c=.o)
	INCLUDE = ft_printf.h

all : $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT_P) all
		cp $(LIBFT_P)libft.a $(NAME)
		ar rc $(NAME) $(OBJ) ft_printf.h

%.o: %.c $(INCLUDE)
		$(CC) $(CCFLAGS) -c -o $@ $<

clean:
		make -C $(LIBFT_P) clean
		rm -f $(OBJ)

fclean : clean
		rm -rf $(NAME)
		rm -rf $(LIBFT_P)/libft.a

re: fclean all
