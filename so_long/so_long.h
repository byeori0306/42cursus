/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 08:13:46 by dahpark           #+#    #+#             */
/*   Updated: 2021/06/24 13:11:15 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
# define TRUE 1
# define FALSE 0
# define EXIT_OK 0
# define EXIT_FAIL 1
# define STD_ERR 2
# define ERR_MALLOC "Memory allocation failed.\n"
# define ERR_WALL "The map must be surrouded by walls.\n"
# define ERR_RECT "The map must be rectangular.\n"
# define ERR_CHAR "The map must have one P and at least one C and one E.\n"

typedef	struct	s_map_info
{
	int			row;
	int			col;
	int			exit;
	int			start_pos;
	int			collectibles;
	char		**map;
}				t_map_info;

typedef	struct	s_img
{
	void		*wall;
	void		*floor;
	void		*closed;
	void		*opened;
	void		*cherry;
	void		*player_start;
	void		*player_w;
	void		*player_a;
	void		*player_s;
	void		*player_d;
}				t_img;

typedef	struct	s_player
{
	int			cur_x;
	int			cur_y;
	int			next_x;
	int			next_y;
	int			movement;
}				t_player;

typedef	struct	s_game
{
	int			end;
	void		*mlx;
	void		*window;
	t_map_info	map_info;
	t_img		img;
	t_player	player;
}				t_game;

void			init_game(t_game *game);
void			init_map_info(t_map_info *map_info);
void			init_player(t_player *p, int x, int y);
void			init_image(t_img *img);
void			destroy_images(t_game *game, t_img *img);
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
void			print_map(t_map_info *map_info);
int				check_cur_pos(char component, t_game *game);
int				check_next_pos(char component, t_game *game);
int				handle_changes(int keycode, t_game *game,
								t_img imgs, t_player *py);
void			set_cur_pos(t_player *p);
void			find_next_pos(int keycode, t_game *game);

#endif
