# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 15:37:49 by elanna            #+#    #+#              #
#    Updated: 2021/06/24 21:09:00 by elanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_SRCS	= ./srcs/client.c ./srcs/utils_1.c ./srcs/utils_2.c 

SERVER_SRCS	= ./srcs/server.c ./srcs/utils_1.c

HEADERS_FILE = includes

CLIENT	= client

SERVER	= server

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

CLIENT_OBJS	= ${CLIENT_SRCS:.c=.o}

SERVER_OBJS	= ${SERVER_SRCS:.c=.o}

%.o: %.c
		${CC} -g ${CFLAGS} -I ${HEADERS_FILE} -o $@ -c $<


all:		${CLIENT} ${SERVER}
		@echo "\n\nWelcome to minitalk project.\nServer (./server) need to be started prior to client (./client).\nClient must receive as arguments :\n1) The server PID displayed by the server\n2) A string which will be displayed by server.\nHave fun !\n"


${CLIENT}:	${CLIENT_OBJS}
		${CC} -o ${CLIENT} ${CLIENT_OBJS}

${SERVER}:	${SERVER_OBJS}
		${CC} -o ${SERVER} ${SERVER_OBJS}

clean:
		rm -f ${CLIENT_OBJS}
		rm -f ${SERVER_OBJS}

fclean: 	clean
		rm -f ${CLIENT}
		rm -f ${SERVER}

re:		fclean all

.PHONY: all clean re 

