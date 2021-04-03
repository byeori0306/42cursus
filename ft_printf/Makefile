CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
SRCS=ft_printf.c\
	 src/ft_print_char.c\
	 src/ft_print_string.c\
	 src/ft_print_pointer.c\
	 src/ft_print_int.c\
	 src/ft_print_unsigned_int.c\
	 src/ft_print_hex.c\
	 src/ft_print_percent.c\
	 src/ft_set_option.c\
	 src/ft_consider_align.c\
	 src/ft_consider_prec.c\
	 src/ft_consider_width.c\
	 util/ft_check.c\
	 util/ft_putchar.c\
	 util/ft_putstr.c\
	 util/ft_utoa.c\
	 util/ft_lldtoa.c\
	 util/ft_convert_hex.c
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
