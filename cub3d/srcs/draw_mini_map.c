/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:34:38 by dahpark           #+#    #+#             */
/*   Updated: 2021/11/13 18:24:50 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_rect(t_game *game, int x, int y)
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

int	draw_mini_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map_info.row)
	{
		x = 0;
		while (x < game->map_info.col)
		{
			if (game->map_info.map[y][x] == '1')
				draw_rect(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}