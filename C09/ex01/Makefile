# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 14:50:30 by ade-feli          #+#    #+#              #
#    Updated: 2020/11/05 14:50:34 by ade-feli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJS	= ${SRCS:.c=.o}
NAME	= libft.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -I includes -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re
