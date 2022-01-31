# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabidal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 20:08:50 by maabidal          #+#    #+#              #
#    Updated: 2022/01/31 19:24:42 by maabidal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BONUS_SRCS 	=	all_instructions.c\
			instructions.c\
			checker.c\
			utils.c\
			setup.c\
			get_next_line.c\
			get_next_line_utils.c

SRCS 	=	all_instructions.c\
			instructions.c\
			main.c\
			utils.c\
			setup.c\
			join.c

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3
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

so:
	$(CC) -fPIC $(CFLAGS) -c $(SRCS) $(BONUSSRCS)
	gcc -shared -o libft.so $(OBJS) $(BNSOBJS)

.PHONY : all clean fclean re bonus
