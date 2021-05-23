CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=push_swap
LIB_PATH=./libft
LIB=./libft/libft.a
SRCS=push_swap.c\
     deque/init.c\
     deque/del.c\
     deque/add.c\
     srcs/instructions.c\
     srcs/check.c
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
