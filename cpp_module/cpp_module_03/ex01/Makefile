# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 18:18:49 by dahpark           #+#    #+#              #
#    Updated: 2022/01/11 19:49:00 by dahpark          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror
NAME		= scavtrap
SRCS		= main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS		= $(SRCS:.cpp=.o)
RM			= rm -f

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re