/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 08:13:46 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/07 11:21:06 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft/libft.h"
# include "minilibx_mms/mlx.h"
# include <stdlib.h>

# define DESTROY_NOTIFY 17
# define KEY_PRESS 2
# define ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define TILE_SIZE 64
# define MIN_COL 3
# define DURATION 30
# define INT_MAX 2147483647
# define WHITE 16777215
# define CNT_X 15
# define CNT_Y 25
# define TRUE 1
# define FALSE 0
# define EXIT_OK 0
# define EXIT_FAIL 1
# define STD_OUT 1
# define STD_ERR 2
# define ERR_MALLOC "Memory allocation failed.\n"
# define ERR_WALL "The map must be surrouded by walls.\n"
# define ERR_RECT "The map must be rectangular.\n"
# define ERR_CHAR "The map must have one P and at least one C and one E.\n"
# define ERR_GNL "File reading failed.\n"

typedef	struct	s_map_info
{
	int			row;
	int			col;
	int			exit;
	int			start_pos;
	int			collectibles;
	int			space;
	int			ghost;
	char		**map;
}				t_map_info;

typedef	struct	s_img
{
	void		*wall;
	void		*floor;
	void		*closed;
	void		*opened;
	void		*cherry;
	void		*start;
	void		*end;
	void		*p_w_1;
	void		*p_w_2;
	void		*p_a_1;
	void		*p_a_2;
	void		*p_s_1;
	void		*p_s_2;
	void		*p_d_1;
	void		*p_d_2;
	void		*enemy_1;
	void		*enemy_2;
}				t_img;

typedef	struct	s_player
{
	int			cur_x;
	int			cur_y;
	int			next_x;
	int			next_y;
	int			movement;
	int			key;
}				t_player;

typedef	struct	s_game
{
	int			end;
	int			start;
	int			cnt;
	void		*mlx;
	void		*window;
	int			flag;
	t_map_info	map_info;
	t_img		img;
	t_player	player;
}				t_game;

void			init_game(t_game *game);
void			init_map_info(t_map_info *map_info);
void			init_player(t_player *p, int x, int y);
void			init_image(t_img *img);
void			destroy(t_game *game);
int				close_window(t_game *game);
int				key_press_event(int keycode, t_game *game);
void			check_argument(int argc, char *file_name);
void			check_screen_size(t_game *game);
void			print_error(char *message);
void			check_map(char *file, t_map_info *map_info);
void			put_image(t_game *game, void *img, int x, int y);
void			draw_map(t_game *game);
void			free_map(t_map_info *map_info, int i);
void			get_map(char *file, t_map_info *map_info);
int				check_cur_pos(char component, t_game *game);
int				check_next_pos(char component, t_game *game);
int				handle_changes(int keycode, t_game *game,
								t_player *py);
void			set_cur_pos(t_player *p);
void			find_next_pos(int keycode, t_game *game);
int				animate(t_game *game);
void			animate_player(t_game *game);
void			add_ghost(t_map_info *m);

#endif
