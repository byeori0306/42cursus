# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 08:03:45 by dahpark           #+#    #+#              #
#    Updated: 2021/07/07 10:34:04 by dahpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=so_long
LIB_DIR=./libft
LIB=./libft/libft.a
MLX_DIR=./minilibx_mms
MLX_LIB=./minilibx_mms/libmlx.dylib
MLX=-L./minilibx_mms -lmlx -framework OpenGL -framework Appkit
GNL = $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)
SRC = $(addprefix srcs/, init.c destroy.c event.c check_error.c check_map.c \
		get_map.c draw_map.c handle_changes.c handle_player_pos.c)
SRCS=so_long.c $(GNL) $(SRC)
OBJS=$(SRCS:.c=.o)
GNL_BONUS = $(addprefix get_next_line_bonus/, \
		get_next_line_bonus.c get_next_line_utils_bonus.c)
SRC_BONUS = $(addprefix srcs_bonus/, add_ghost_bonus.c animate_bonus.c \
		check_error_bonus.c check_map_bonus.c destroy_bonus.c \
		draw_map_bonus.c event_bonus.c get_map_bonus.c init_bonus.c \
		handle_player_pos_bonus.c handle_changes_bonus.c)
SRCS_BONUS=so_long_bonus.c $(GNL_BONUS) $(SRC_BONUS)
OBJS_BONUS=$(SRCS_BONUS:.c=.o)
RM=rm -f

all: $(NAME)

$(NAME): $(OBJS) libft
	@make -C $(LIB_DIR)
	@make -C $(MLX_DIR)
	cp $(MLX_LIB) ./libmlx.dylib
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIB) -o $(NAME)

bonus: $(OBJS_BONUS) libft
	@make -C $(LIB_DIR)
	@make -C $(MLX_DIR)
	cp $(MLX_LIB) ./libmlx.dylib
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX) $(LIB) -o $(NAME)

clean:
	@make -C $(LIB_DIR) clean
	@make -C $(MLX_DIR) clean
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@$(RM) ./libmlx.dylib
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
