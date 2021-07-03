# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/03 16:45:38 by dahpark           #+#    #+#              #
#    Updated: 2021/07/03 16:45:41 by dahpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=pipex
LIB_PATH=./libft
LIB=./libft/libft.a
SRCS=pipex.c\
	get_path.c
OBJS=$(SRCS:.c=.o)
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS) libft
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
	@make -C $(LIB_PATH) clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIB_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
