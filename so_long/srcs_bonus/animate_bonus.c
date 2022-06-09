/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 06:35:23 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/07 11:17:47 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static	void	animate_ghost(t_game *game, void *image)
{
	t_map_info	m;
	int			row;
	int			col;

	m = game->map_info;
	row = 0;
	while (row < m.row)
	{
		col = 0;
		while (col < m.col)
		{
			if (m.map[row][col] == 'G')
				put_image(game, image, col, row);
			col++;
		}
		row++;
	}
}

static	void	player_open(t_game *game)
{
	t_img		imgs;
	t_player	py;
	int			i;

	imgs = game->img;
	py = game->player;
	i = 0;
	if (py.key == KEY_W)
		put_image(game, imgs.p_w_1, py.next_x, py.next_y);
	else if (py.key == KEY_A)
		put_image(game, imgs.p_a_1, py.next_x, py.next_y);
	else if (py.key == KEY_S)
		put_image(game, imgs.p_s_1, py.next_x, py.next_y);
	else if (py.key == KEY_D)
		put_image(game, imgs.p_d_1, py.next_x, py.next_y);
	animate_ghost(game, imgs.enemy_1);
}

static	void	player_open_little(t_game *game)
{
	t_img		imgs;
	t_player	py;
	int			i;

	imgs = game->img;
	py = game->player;
	i = 0;
	if (py.key == KEY_W)
		put_image(game, imgs.p_w_2, py.next_x, py.next_y);
	else if (py.key == KEY_A)
		put_image(game, imgs.p_a_2, py.next_x, py.next_y);
	else if (py.key == KEY_S)
		put_image(game, imgs.p_s_2, py.next_x, py.next_y);
	else if (py.key == KEY_D)
		put_image(game, imgs.p_d_2, py.next_x, py.next_y);
	animate_ghost(game, imgs.enemy_2);
}

void			animate_player(t_game *game)
{
	t_img		imgs;
	t_player	py;

	imgs = game->img;
	py = game->player;
	if (check_cur_pos('E', game) == TRUE)
		put_image(game, imgs.closed, py.cur_x, py.cur_y);
	else
		put_image(game, imgs.floor, py.next_x, py.next_y);
	if (game->flag == 1)
		player_open(game);
	else if (game->flag == 2)
		player_open_little(game);
}
