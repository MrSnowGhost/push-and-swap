# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybensell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 08:36:51 by ybensell          #+#    #+#              #
#    Updated: 2022/01/07 14:40:55 by ybensell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap

SRC = push_a.c push_b.c rra.c	swap_a.c ra.c rrb.c swap_b.c main.c rb.c\
	 sort_list.c tools.c list_case.c tools2.c 

OBJ = ${SRC:.c=.o}

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT : libft/libft.a

HEADER = header.h

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(FLAG) $(OBJ) libft/libft.a -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

