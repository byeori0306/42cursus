/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:06:41 by dahpark           #+#    #+#             */
/*   Updated: 2021/11/13 19:59:18 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "minilibx_mms/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h> 
# include <stdio.h>

# define DESTROY_NOTIFY 17
# define KEY_PRESS 2
# define ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define TILE_SIZE 32
# define ERRMEM "System error : memory allocation failed"

typedef	struct	s_map_info
{
	int		row;
	int		col;
	int		start_pos;
	int		start_line;
	char	**map;
}				t_map_info;

typedef struct	s_elem_info
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
}				t_elem_info;

typedef struct	s_player
{
	int		pos_x;
	int		pos_y;
}				t_player;

typedef	struct	s_game
{
	void		*mlx;
	void		*window;
	t_map_info	map_info;
	t_elem_info	elem_info;
	t_player	player;
}				t_game;

void    check_arg(int argc, char **argv);
void    check_file(t_game *game, char *file_name);
void    init_info(t_game *game);
void	init_window(t_game *game);
void	get_elem_info(t_elem_info *elem_info, char *line);
void	get_map_info(t_game *game, char *line);
void	get_map(t_map_info *map_info, char *file_name);
int		draw_mini_map(t_game *game);
int		close_window(t_game *game);
int		key_press(int keycode, t_game *game);

void    print_err(char *msg);

#endif