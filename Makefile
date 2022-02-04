# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabidal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 20:08:50 by maabidal          #+#    #+#              #
#    Updated: 2022/02/04 17:32:56 by maabidal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BONUS_SRCS 	=	all_instructions.c\
			instructions.c\
			checker_bonus.c\
			utils.c\
			setup.c\
			get_next_line_bonus.c\
			get_next_line_utils_bonus.c

SRCS 		=	all_instructions.c\
			instructions.c\
			main.c\
			utils.c\
			setup.c\
			join.c

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
OBJS	= $(SRCS:.c=.o)
BNSOBJS	= $(BONUS_SRCS:.c=.o)
BNS_NAME = checker

all : $(NAME)

bonus : $(BNSOBJS)
	gcc -o $(BNS_NAME) $(BNSOBJS)

$(NAME) : $(OBJS)
	gcc -o $(NAME) $(OBJS)

.o : .c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

clean : 
	$(RM) $(OBJS) $(BNSOBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BNS_NAME)

re :    fclean all

.PHONY : all clean fclean re bonus
