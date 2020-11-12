# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 19:19:23 by ade-feli          #+#    #+#              #
#    Updated: 2020/11/08 19:19:28 by ade-feli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c check.c utilities.c search.c recursive.c numbers.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= rush-02

.c.o	:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
all		:	${OBJS}
			${CC} -o ${NAME} ${OBJS}
${NAME}	:	all
clean	:
			rm -f ${OBJS}
fclean	:	clean
			rm -f ${NAME}
re		:	fclean all
.PHONY	: all clean fclean re
