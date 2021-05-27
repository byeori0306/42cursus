CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=push_swap
LIB_PATH=./libft
LIB=./libft/libft.a
SRCS=push_swap.c\
     srcs/list/init.c\
     srcs/list/del.c\
     srcs/list/add.c\
     srcs/instructions/push.c\
     srcs/instructions/swap.c\
     srcs/instructions/rotate.c\
     srcs/instructions/reverse_rotate.c\
     srcs/check.c\
     srcs/find_median.c\
     srcs/sort_3.c\
     srcs/sort_5.c\
     srcs/sort.c
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
