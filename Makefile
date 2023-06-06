# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 06:16:56 by rsiqueir          #+#    #+#              #
#    Updated: 2023/06/04 22:24:35 by rsiqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube
LFLAGS = -Lmlx_linux/ -lmlx -Lmlx_linux/lib -lXext -lX11 -lm -lbsd
# CFLAGS = -Wall -Werror -Wextra
LIBPATH = ./libft
CC = gcc
AR = ar rcs

SRCS =	get_next_line/get_next_line.c		\
		get_next_line/get_next_line_utils.c	\
		src/main.c	\
		src/window.c \
		src/draw.c			

OBJS = $(SRCS:%.c=%.o)

all:	${NAME}

%.o: %.c
	$(CC) -I./include -c $< -o $@

${NAME}:	${OBJS}
			make	-C ./mlx_linux
			make	-C ${LIBPATH} bonus
			gcc ${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a mlx_linux/libmlx_Linux.a ${LFLAGS}

clean:
		make -C ./mlx_linux clean
		make -C ${LIBPATH} clean
		rm -rf src/*.o
		rm -rf get_next_line/*.o

fclean:	clean
	rm -rf ${NAME}
	rm -rf mlx_linux/libmlx_Linux.a
	make -C ${LIBPATH} fclean

re:		fclean all
