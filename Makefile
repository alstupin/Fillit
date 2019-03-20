# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juriot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 11:59:19 by juriot            #+#    #+#              #
#    Updated: 2018/11/14 11:59:20 by juriot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fillit

INCLUDES =	-Iincludes/ -Ilibft/includes

SOURCES =	main.c \
			mapper.c \
			fillit.c \
			cleaner.c \
			parsing.c \
			validation.c \
			listing.c

OFILES = $(SOURCES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY : all

all : $(NAME)

$(NAME) : $(OFILES)
	make -C libft/ fclean && make -C libft/
	$(CC) -o $(NAME) $(INCLUDES) $(OFILES) libft/libft.a

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<  

clean :
	make clean -C libft/
	rm -f $(OFILES)

fclean : clean
	make fclean -C libft/
	rm -f $(NAME)

re : fclean all
