/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:06:41 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/13 20:54:41 by dahpark          ###   ########seoul.kr  */
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
# define FOV M_PI / 3

# define NO 1
# define SO 2
# define WE 3
# define EA 4

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

typedef struct s_texture
{
	int		*texture;
	int	width;
	int	height;
}				t_texture;

typedef struct s_elem_info
{
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
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
int		check_file_type(char *file_name, char *extension);
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

int		close_window(t_game *game);
int		key_press(int keycode, t_game *game);
int 	key_release(int keycode, t_game *game);

int		change_player_pos(int keycode, t_game *game, t_player *pl);
void 	reset_player_dir(int keycode, t_player *pl);

void	cast_rays(t_game *game);
void	check_horz(t_game *game, t_temp_ray *horz);
void	check_vert(t_game *game, t_temp_ray *vert);

int		render(t_game *game);
void	render_col(t_game *game, int column_id);

void	paint_wall(t_game *game, int column_id);
void	paint_sky(t_game *game, int column_id, int top);
void	paint_ground(t_game *game, int column_id, int bottom);

void	print_err(char *msg);
int		get_2d_len(char **arr);
void	free_2d(char **arr);

#endif