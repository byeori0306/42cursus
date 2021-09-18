# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 14:55:35 by dahpark           #+#    #+#              #
#    Updated: 2021/09/17 07:37:32 by dahpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
# CFLAGS=-Wall -Wextra -Werror
LDFLAGS=-lpthread
NAME=philo
UTILS=$(addprefix utils/, ft_atoi.c ft_isdigit.c ft_putstr_fd.c utils.c)
SRCS=philo.c\
	init.c\
	dinning.c\
	routine.c\
	use_forks.c\
	die.c\
	$(UTILS)
OBJS=$(SRCS:.c=.o)
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
