# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 11:29:34 by lmedrano          #+#    #+#              #
#    Updated: 2023/07/11 18:10:21 by lmedrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE 		= \033[38;5;69m
ORANGE 		= \033[38;5;215m
GREEN 		= \033[38;5;82m
RESET 		= \033[0m

SRCS 		= server.c client.c

OBJS 		= ${SRCS:.c=.o}

NAME		= minitalk

CC 		= gcc

CFLAGS		= -Wall -Werror -Wextra -Ilibft -Iprintf

RM		= rm -rf

$(NAME):	server client

server:		server.o
		@echo "$(RESET)$(ORANGE)ASSEMBLING -SERVER-$(RESET)"
		make -C libft
		make -C printf
		${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lftprintf -o server
		@echo "$(RESET)$(GREEN)-SERVER- HAS ASSEMBLED ✓$(RESET)"

client:		client.o
		@echo "$(RESET)$(ORANGE)ASSEMBLING -CLIENT-$(RESET)"
		make -C libft
		make -C printf
		${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lftprintf -o client
		@echo "$(RESET)$(GREEN)-CLIENT- HAS ASSEMBLED ✓$(RESET)"

		
libft:		@echo "$(RESET)$(ORANGE)ASSEMBLING -LIBFT-$(RESET)"
		make -C libft
		@echo "$(RESET)$(GREEN)-LIBFT- HAS ASSEMBLED ✓$(RESET)"

printf:		@echo "$(RESET)$(ORANGE)ASSEMBLING -PRINTF-$(RESET)"
		make -C printf
		@echo "$(RESET)$(GREEN)-PRINTF- HAS ASSEMBLED ✓$(RESET)"


all:		$(NAME)


clean:		
			@echo "$(RESET)$(ORANGE)I'M CLEANING OUT MY CLOSET...$(RESET)"
			make clean -C libft
			make clean -C printf
			$(RM) $(OBJS)
			@echo "$(RESET)$(GREEN)CLEANED ✓$(RESET)"

fclean:		clean
			@echo "$(RESET)$(ORANGE)ONE MORE TIME...$(RESET)"
			$(RM) server client
			@echo "$(RESET)$(GREEN)ALL CLEANED ✓✓$(RESET)"

re:			fclean all

.PHONY:		all libft printf clean fclean re
