# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/03 16:45:38 by dahpark           #+#    #+#              #
#    Updated: 2021/07/05 17:51:24 by dahpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=pipex
UTILS=$(addprefix utils/, ft_putchar_fd.c ft_putstr_fd.c ft_split.c \
		ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c ft_strncmp.c)
SRCS=pipex.c\
	get_path.c\
	redirect.c\
	execute_cmd.c\
	print_error.c\
	$(UTILS)
OBJS=$(SRCS:.c=.o)
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
