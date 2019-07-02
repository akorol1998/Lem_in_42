# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akorol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 13:23:40 by akorol            #+#    #+#              #
#    Updated: 2019/06/03 13:23:41 by akorol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC =   main.c	\
		file.c	\
		file1.c \
		file2.c \
		file3.c \
		file4.c \
		file5.c \
		trash.c \
		lems.c \
		help_file.c \

CFLAGS = -Wextra -Wall -Werror

LIB = printf/libftprintf.a

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):$(LIB) $(OBJ)
	gcc -g -o $@ $(OBJ) $(LIB)

$(OBJ):%.o:%.c
	gcc $(CFLAGS) -c $< -o $@

$(LIB):
	make -C printf

clean:
	make clean -C printf
	rm -f *.o

fclean: clean
	make fclean -C printf
	rm -f $(NAME)

re: fclean all