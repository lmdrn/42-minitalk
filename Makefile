# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmedrano <lmedrano@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 11:29:34 by lmedrano          #+#    #+#              #
#    Updated: 2023/07/20 09:40:39 by lmedrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE 		= \033[38;5;69m
ORANGE 		= \033[38;5;215m
GREEN 		= \033[38;5;82m
RESET 		= \033[0m

CLIENT			= client

SERVER			= server

SERVER_SRCS 		= server.c \
			  utils.c

CLIENT_SRCS 		= client.c \
			  utils.c

CLIENT_OBJS 		= ${CLIENT_SRCS:.c=.o}

SERVER_OBJS 		= ${SERVER_SRCS:.c=.o}

CC 		= gcc

CFLAGS		= -Wall -Werror -Wextra

RM		= rm -rf


$(SERVER):	$(SERVER_OBJS)
		make -C ft_printf
		@echo "$(RESET)$(ORANGE)ASSEMBLING -SERVER-$(RESET)"
		${CC} ${CFLAGS} $(SERVER_OBJS) ft_printf/ft_printf.a -o $(SERVER)
		@echo "$(RESET)$(GREEN)-SERVER- HAS ASSEMBLED ✓$(RESET)"

$(CLIENT):	$(CLIENT_OBJS)
		make -C ft_printf
		@echo "$(RESET)$(ORANGE)ASSEMBLING -CLIENT-$(RESET)"
		${CC} ${CFLAGS} $(CLIENT_OBJS) ft_printf/ft_printf.a -o $(CLIENT)
		@echo "$(RESET)$(GREEN)-CLIENT- HAS ASSEMBLED ✓$(RESET)"

all:		$(SERVER) $(CLIENT)

clean:
			@echo "$(RESET)$(ORANGE)I'M CLEANING OUT MY CLOSET...$(RESET)"
			make clean -C ft_printf
			$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)
			@echo "$(RESET)$(GREEN)CLEANED ✓$(RESET)"

fclean:		clean
			@echo "$(RESET)$(ORANGE)ONE MORE TIME...$(RESET)"
			$(RM) $(CLIENT) $(SERVER)
			@echo "$(RESET)$(GREEN)ALL CLEANED ✓✓$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re
