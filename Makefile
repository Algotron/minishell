# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkleynts <tkleynts@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 11:11:28 by tkleynts          #+#    #+#              #
#    Updated: 2020/11/27 11:27:38 by tkleynts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -I./includes
NAME = Minishell
LIBFT = libft/libft.a
INCLUDES = includes/mshell.h 
SRC_PATH = srcs
SRC_NAME =	main.c 

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(INCLUDES) $(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
			@printf "\r\033[48;5;15;30m✅ $(NAME)\033[0m\033[K\n"

$(LIBFT) : 
			@make -C libft all
			@printf "\r\033[48;5;15;30m✅ libft\033[0m\033[K\n"
clean :
			@rm -f src/$(OBJS)
			@printf "\r\033[48;5;15;30m✅ clean\033[0m\033[K\n"

fclean :	
			@rm -f src/$(OBJS)
			@rm -f $(NAME)
			@printf "\r\033[48;5;15;30m✅ fclean\033[0m\033[K\n"

re: fclean all