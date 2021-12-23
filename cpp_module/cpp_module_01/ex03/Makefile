# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 15:12:29 by dahpark           #+#    #+#              #
#    Updated: 2021/12/23 15:13:00 by dahpark          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror
NAME		= violence
SRCS		= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
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