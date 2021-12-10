/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:06:41 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/10 20:15:08 by dahpark          ###   ########seoul.kr  */
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
# define KEY_RELEASE 3
# define ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define WIDTH 640
# define HEIGHT 640

# define TILE_SIZE 64
# define TEX_SIZE 64
# define PL_SIZE 4

# define NO 1
# define SO 2
# define WE 3
# define EA 4

# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define YELLOW 0x00FFFF00

# define FOV M_PI / 3
# define GAP 2

# define TRUE 1
# define FALSE 0

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
	int	*no;
	int	*so;
	int	*we;
	int	*ea;
	int		f;
	int		c;
}				t_elem_info;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	int		turn_dir; // -1 if left, +1 if right
	int		walk_dir; // -1 if back, +1 if front
	double	rotation_angle;
	double	walk_speed;
	double	turn_speed;
}				t_player;

typedef struct s_temp_ray
{
	double	first_x;
	double	first_y;
	double	step_x;
	double	step_y;
	double	intersect_x;
	double	intersect_y;
	double	distance;
	int		found_wall;
}				t_temp_ray;

typedef struct  s_ray
{
	double	ray_angle;
	double	intersect_x;
	double	intersect_y;
	double	distance;
	int		is_facing_down;
	int		is_facing_up;
	int		is_facing_right;
	int		is_facing_left;
	int		hit_vertical;
}				t_ray;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_line;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_render
{
	double	correct_dist;
	double	dist_to_plane;
	int		projected_wall_height;
	int		top;
	int		bottom;
	int		dir;
}				t_render;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map_info	map_info;
	t_elem_info	elem_info;
	t_player	player;
	t_img		img;
	t_ray		ray;
	t_render	render;
}				t_game;

void	check_arg(int argc, char **argv);
void	check_file(t_game *game, char *file_name);
void	check_map(t_map_info *map_info);
void	init_info(t_game *game);
void	init_map(t_map_info *map_info);
void	init_player(t_player *pl, char dir);
void	init_window(t_game *game);
void	get_elem_info(t_game *game, t_elem_info *elem_info, char *line);
void	get_map_info(t_game *game, char *line);
void	get_map(t_map_info *map_info, char *file_name);
void	modify_map(t_map_info *map_info);

int		draw_mini_map(t_game *game);
void	draw_rays(t_game *game);

int		render(t_game *game);
void	render_col(t_game *game, int column_id);

int		close_window(t_game *game);
int		key_press(int keycode, t_game *game);
int 	key_release(int keycode, t_game *game);
int		move(int keycode, t_game *game);
void	reset(int keycode, t_player *pl);

void	print_err(char *msg);
int		get_2d_len(char **arr);
void	free_2d(char **arr);

#endif