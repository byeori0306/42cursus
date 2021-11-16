/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:34:38 by dahpark           #+#    #+#             */
/*   Updated: 2021/11/16 20:02:36 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_wall(t_game *game, int x, int y)
{
	int	dx;
	int	dy;

	dx = x * TILE_SIZE;
	dy = y * TILE_SIZE;
	while (dy < (y + 1) * TILE_SIZE)
	{
		dx = x * TILE_SIZE;
		while (dx < (x + 1) * TILE_SIZE)
		{
			mlx_pixel_put(game->mlx, game->window, x + dx, y + dy, 0x00FFFFFF);
			dx++;
		}
		dy++;
	}
}

static void	draw_player(t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos_x;
	y = game->player.pos_y;
	while (y < game->player.pos_y + PL_SIZE)
	{
		x = game->player.pos_x;
		while (x < game->player.pos_x + PL_SIZE)
		{
			mlx_pixel_put(game->mlx, game->window, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
}

int	draw_mini_map(t_game *game)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < game->map_info.row + 1)
	{
		x = 1;
		while (x < game->map_info.col + 1)
		{
			if (game->map_info.map[y][x] == '1')
				draw_wall(game, x - 1, y - 1);
			x++;
		}
		y++;
	}
	draw_player(game);
	return (0);
}
