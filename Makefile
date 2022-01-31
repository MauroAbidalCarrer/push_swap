# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabidal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 20:08:50 by maabidal          #+#    #+#              #
#    Updated: 2022/01/30 20:26:27 by maabidal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	=	all_instructions.c\
			instructions.c\
			main.c\
			utils.c\
			join.c

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
OBJS	= $(SRCS:.c=.o)
BNSOBJS	= $(BONUSSRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	gcc -o $(NAME) $(OBJS)

.o : .c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

clean : 
	$(RM) $(OBJS) $(BNSOBJS)

fclean : clean
	$(RM) $(NAME)

re :    fclean all

so:
	$(CC) -fPIC $(CFLAGS) -c $(SRCS) $(BONUSSRCS)
	gcc -shared -o libft.so $(OBJS) $(BNSOBJS)

.PHONY : all clean fclean re
