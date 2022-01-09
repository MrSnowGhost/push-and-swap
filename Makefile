# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybensell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 08:36:51 by ybensell          #+#    #+#              #
#    Updated: 2022/01/09 10:56:48 by ybensell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap
NAME_BONUS = checker

SRC = push_a.c push_b.c rra.c	swap_a.c ra.c rrb.c swap_b.c main.c rb.c\
	 sort_list.c tools.c list_case.c tools2.c 
BONUS = bonus/ss.c bonus/rr.c bonus/rrr.c bonus/checker.c bonus/get_next_line.c\
	   	bonus/get_next_line_utils.c bonus/utils.c bonus/ra.c bonus/rb.c\
		bonus/push_a.c bonus/push_b.c bonus/swap_a.c bonus/swap_b.c\
		bonus/rra.c bonus/rrb.c bonus/utils2.c bonus/utils3.c

OBJ = ${SRC:.c=.o}
	
OBJ_BONUS = ${BONUS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT = libft/libft.a

HEADER = header.h

%.o:%.c $(HEADER) 
	$(CC) $(CFLAGS) -c $< -o $@ 

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT) :
		cd libft && make 

bonus : $(OBJ_BONUS) $(HEADER) $(LIBFT)
		$(CC) $(CFLAG) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean :
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)	

re : fclean all 

