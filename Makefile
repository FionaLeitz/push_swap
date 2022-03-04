# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleitz <fleitz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/04 10:53:01 by fleitz            #+#    #+#              #
#    Updated: 2022/03/04 10:53:31 by fleitz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRCS		= main.c					\
			  errors.c					\
			  movements.c				\
			  movements2.c				\
			  make_stack.c				\
			  sort.c					\
			  sort2.c					\
			  strings.c					\
			  under_six.c 				\
			  utils.c					\
			  utils2.c					\
			  big_sort.c				\
			  big_sort2.c				\
			  
OBJS		= ${SRCS:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

LIB			= libft/libft.a

all:		${NAME}

${NAME}:	${OBJS}
			make -C libft	
			${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}

%.o: %.c
			${CC} ${CFLAGS} -c $< -o $@

clean:
			make clean -C libft	
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME} ${LIB}

re:			fclean all

.PHONY:		clean fclean re all
