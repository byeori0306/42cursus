/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_changes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 04:08:55 by dahpark           #+#    #+#             */
/*   Updated: 2021/06/24 08:09:06 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	put_player(int keycode, t_game *game)
{
	t_img		imgs;
	t_player	py;

	imgs = game->img;
	py = game->player;
	if (keycode == KEY_W)
		put_image(game, imgs.player_w, py.next_x, py.next_y);
	else if (keycode == KEY_A)
		put_image(game, imgs.player_a, py.next_x, py.next_y);
	else if (keycode == KEY_S)
		put_image(game, imgs.player_s, py.next_x, py.next_y);
	else if (keycode == KEY_D)
		put_image(game, imgs.player_d, py.next_x, py.next_y);
}

int				check_cur_pos(char component, t_game *game)
{
	int x;
	int y;

	x = game->player.cur_x;
	y = game->player.cur_y;
	if (game->map_info.map[y][x] == component)
		return (TRUE);
	else
		return (FALSE);
}

int				check_next_pos(char component, t_game *game)
{
	int x;
	int y;

	x = game->player.next_x;
	y = game->player.next_y;
	if (game->map_info.map[y][x] == component)
		return (TRUE);
	else
		return (FALSE);
}

int				handle_changes(int keycode, t_game *game, t_img i, t_player *py)
{
	if (game->end == TRUE)
		return (0);
	find_next_pos(keycode, game);
	if (check_cur_pos('E', game) == FALSE)
		put_image(game, i.floor, py->cur_x, py->cur_y);
	else
		put_image(game, i.closed, py->cur_x, py->cur_y);
	if (check_next_pos('C', game) == TRUE)
		put_image(game, i.floor, py->next_x, py->next_y);
	put_player(keycode, game);
	set_cur_pos(py);
	if (check_cur_pos('C', game) == TRUE)
	{
		game->map_info.collectibles--;
		game->map_info.map[py->cur_y][py->cur_x] = '0';
	}
	else if (check_cur_pos('E', game) == TRUE
	&& game->map_info.collectibles == 0)
	{
		put_image(game, i.opened, py->cur_x, py->cur_y);
		game->end = TRUE;
	}
	return (0);
}
