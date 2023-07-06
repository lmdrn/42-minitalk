# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 11:29:34 by lmedrano          #+#    #+#              #
#    Updated: 2023/07/06 14:58:03 by lmedrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE 		= \033[38;5;69m
ORANGE 		= \033[38;5;215m
GREEN 		= \033[38;5;82m
RESET 		= \033[0m

SRCS1 		= server.c

SRCS2 		= client.c

OBJS1 		= ${SRCS1:.c=.o}

OBJS2 		= ${SRCS2:.c=.o}

prog01		= server

prog02		= client

CC 		= gcc

CFLAGS		= -Wall -Werror -Wextra -g -fsanitize=address

RM		= rm -rf

${prog01}:	${OBJS1}
			@echo "$(RESET)$(ORANGE)ASSEMBLING $(prog01)$(RESET)"
			${CC} ${CFLAGS} ${OBJS1} -o ${prog01}
			@echo "$(RESET)$(GREEN)$(prog01) HAS ASSEMBLED ✓$(RESET)"

${prog02}:	${OBJS2}
			@echo "$(RESET)$(ORANGE)ASSEMBLING $(prog02)$(RESET)"
			${CC} ${CFLAGS} ${OBJS2} -o ${prog02}
			@echo "$(RESET)$(GREEN)$(prog02) HAS ASSEMBLED ✓$(RESET)"

all:		$(prog01) $(prog02)


clean:		
			@echo "$(RESET)$(ORANGE)I'M CLEANING OUT MY CLOSET...$(RESET)"
			@echo "$(RESET)$(GREEN)CLEANED ✓$(RESET)"

fclean:		clean
			@echo "$(RESET)$(ORANGE)ONE MORE TIME...$(RESET)"
			${RM} ${OBJS1} ${prog01}
			${RM} ${OBJS2} ${prog02}
			@echo "$(RESET)$(GREEN)ALL CLEANED ✓✓$(RESET)"

re:			fclean all

.PHONY:		all test clean fclean re
