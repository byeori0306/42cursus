/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:29:45 by dahpark           #+#    #+#             */
/*   Updated: 2021/11/27 21:51:30 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_wall(t_game *game, int keycode, int x, int y)
{
	int cur_pixel;

	if (keycode == KEY_W || keycode == KEY_A)
		cur_pixel = x + y * (game->map_info.col + 1) * TILE_SIZE;
	else if (keycode == KEY_S || keycode == KEY_D)
		cur_pixel = (x + PL_SIZE / 2) + (y + PL_SIZE) * (game->map_info.col + 1) * TILE_SIZE;
	if (game->img.data[cur_pixel] == WHITE)
		return (1);
	return (0);
}

static void	change_player_pos(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos_x;
	y = game->player.pos_y;
	if (keycode == KEY_W)
		y -= 2;
	else if (keycode == KEY_A)
		x -= 2;
	else if (keycode == KEY_S)
		y += 2;
	else if (keycode == KEY_D)
		x += 2;
	if (is_wall(game, keycode, x, y))
		return ;
	else
	{
		game->player.pos_x = x;
		game->player.pos_y = y;
	}
}

int	move(int keycode, t_game *game)
{
	change_player_pos(keycode, game);
	return (0);
}
