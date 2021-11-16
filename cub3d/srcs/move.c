/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:29:45 by dahpark           #+#    #+#             */
/*   Updated: 2021/11/16 20:03:53 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	change_player_pos(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos_x;
	y = game->player.pos_y;
	if (keycode == KEY_W)
		y -= 5;
	else if (keycode == KEY_A)
		x -= 5;
	else if (keycode == KEY_S)
		y += 5;
	else if (keycode == KEY_D)
		x += 5;
	if (game->map_info.map[y / (TILE_SIZE + 1)][x / (TILE_SIZE + 1)] == '1')
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
	mlx_clear_window(game->mlx, game->window);
	return (0);
}
