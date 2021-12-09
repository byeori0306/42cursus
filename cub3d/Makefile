# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 21:06:34 by dahpark           #+#    #+#              #
#    Updated: 2021/12/09 16:02:09 by dahpark          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3
NAME	= cub3d
LIB_DIR	= ./libft
LIB		= ./libft/libft.a
MLX_DIR	= ./minilibx_mms
MLX_LIB	= ./minilibx_mms/libmlx.dylib
MLX		= -L./minilibx_mms -lmlx -framework OpenGL -framework Appkit
GNL		= $(addprefix get_next_line/, get_next_line.c \
									get_next_line_utils.c)
INIT	= $(addprefix init/, check_arg.c \
							check_file.c \
							check_map.c \
							init.c \
							get_element_info.c \
							get_map_info.c \
							get_map.c)
UTIL	= $(addprefix util/, 2d_array_util.c \
							print_error.c)
SRCS	= cub3d.c \
		srcs/event.c \
		srcs/draw_mini_map.c \
		srcs/move.c \
		srcs/draw_ray.c \
		srcs/render_walls.c \
		$(GNL) \
		$(INIT) \
		$(UTIL)
OBJS	= $(SRCS:.c=.o)
RM		= rm -f

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