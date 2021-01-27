# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/01 11:44:34 by shenquin          #+#    #+#              #
#    Updated: 2020/12/01 11:44:36 by shenquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR = ./

SRCS	= ft_printc.c ft_printd.c ft_printf.c ft_printp.c ft_printpercent.c \
			ft_prints.c ft_printu.c ft_printx.c printf_utils1.c printf_utils2.c \
			printf_utils3.c

OBJS	= $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))

NAME	= libftprintf.a

CC	= gcc
RM	= rm -f

.c.o:
			${CC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			@echo "${OUT_PREFIX}\033[38;5;46mLibrary compiled\033[0m"

all: 		${NAME}

clean:
			${RM} ${OBJS} ${BOBJ}
			@echo "${OUT_PREFIX}\033[38;5;46mObjects cleaned\033[0m"

fclean:		clean
			${RM} ${NAME}
			@echo "${OUT_PREFIX}\033[38;5;46mLibrary cleaned\033[0m"

re:		fclean all

c:		all clean

.PHONY:		clean fclean re all c