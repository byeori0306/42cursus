CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=so_long
LIB_DIR=./libft
LIB=./libft/libft.a
MLX_DIR=./minilibx_mms
MLX_LIB=./minilibx_mms/libmlx.dylib
MLX=-L./minilibx_mms -lmlx -framework OpenGL -framework Appkit
SRCS=so_long.c\
	 srcs/init.c\
	 srcs/destroy.c\
 	 srcs/event.c\
	 srcs/check_error.c\
     srcs/check_map.c\
     srcs/get_map.c\
	 srcs/draw_map.c\
	 srcs/handle_player_pos.c\
	 srcs/handle_changes.c\
     get_next_line/get_next_line.c\
     get_next_line/get_next_line_utils.c
OBJS=$(SRCS:.c=.o)
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS) libft
	@make -C $(LIB_DIR)
	@make -C $(MLX_DIR)
	cp $(MLX_LIB) ./libmlx.dylib
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIB) -o $(NAME)

clean:
	@make -C $(LIB_DIR) clean
	@make -C $(MLX_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@$(RM) ./libmlx.dylib
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
