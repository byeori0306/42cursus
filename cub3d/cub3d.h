/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:06:41 by dahpark           #+#    #+#             */
/*   Updated: 2021/11/27 20:52:40 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "minilibx_mms/mlx.h"
# include <sys/errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h> 
# include <stdio.h>
# include <string.h>
# include <math.h>

# define DESTROY_NOTIFY 17
# define KEY_PRESS 2
# define ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define TILE_SIZE 32
# define PL_SIZE 4

# define WHITE 0x00FFFFFF
# define BLACK 0x00000000

# define MLX_SYNC_IMAGE_WRITABLE    1 
# define MLX_SYNC_WIN_FLUSH_CMD     2
# define MLX_SYNC_WIN_CMD_COMPLETED 3

typedef struct s_map_info
{
	int		row;
	int		col;
	int		start_pos;
	int		start_line;
	char	**map;
}				t_map_info;

typedef struct s_elem_info
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
}				t_elem_info;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}				t_player;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_line;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map_info	map_info;
	t_elem_info	elem_info;
	t_player	player;
	t_img		img;
}				t_game;

void	check_arg(int argc, char **argv);
void	check_file(t_game *game, char *file_name);
void	check_map(t_map_info *map_info);
void	init_info(t_game *game);
void	init_map(t_map_info *map_info);
void	init_window(t_game *game);
void	get_elem_info(t_elem_info *elem_info, char *line);
void	get_map_info(t_game *game, char *line);
void	get_map(t_map_info *map_info, char *file_name);

int		draw_mini_map(t_game *game);
int		close_window(t_game *game);
int		key_press(int keycode, t_game *game);
int		move(int keycode, t_game *game);

void	print_err(char *msg);
int		get_2d_len(char **arr);
void	free_2d(char **arr);

#endif