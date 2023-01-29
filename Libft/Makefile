# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazaroua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 10:14:47 by mazaroua          #+#    #+#              #
#    Updated: 2022/10/18 10:27:16 by mazaroua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
AR = ar rc
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_atoi.c ft_putchar_fd.c ft_putnbr_fd.c

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o:%.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

