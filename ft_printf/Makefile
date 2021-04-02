CC=gcc
CFLAGS=-Wall -Wextra
NAME=libftprintf.a
SRCS=ft_printf.c\
	 src/ft_putchar.c\
	 src/ft_putstr.c\
	 src/ft_utoa.c\
	 src/ft_check.c\
	 src/ft_set_option.c\
	 src/ft_print_int.c\
	 src/ft_print_unsigned_int.c\
	 src/ft_print_hex.c\
	 src/ft_convert_hex.c\
	 src/ft_print_percent.c\
	 src/ft_print_string.c\
	 src/ft_print_char.c\
	 src/ft_print_pointer.c
OBJS=$(SRCS:.c=.o)
AR=ar rsc
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS) libft
	@$(MAKE) -C ./libft
	cp libft/libft.a $@
	$(AR) $@ $(OBJS)

clean:
	@$(MAKE) -C ./libft clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C ./libft fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
