/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:34:38 by dahpark           #+#    #+#             */
/*   Updated: 2021/11/27 20:38:04 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			game->img.data[x + y * (game->map_info.col + 1) * TILE_SIZE] = 0x00FF0000;
			x++;
		}
		y++;
	}
}

static void	draw_tile(t_game *game, int x, int y, int color)
{
	int	dx;
	int	dy;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	dy = 0;
	while (dy < TILE_SIZE)
	{
		dx = 0;
		while (dx < TILE_SIZE)
		{
			game->img.data[(x + dx) + (y + dy) * (game->map_info.col + 1) * TILE_SIZE] = color;
			dx++;
		}
		dy++;
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
				draw_tile(game, x - 1, y - 1, WHITE);
			else
				draw_tile(game, x - 1, y - 1, BLACK);
			x++;
		}
		y++;
	}
	draw_player(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img_ptr, 0, 0);
	return (0);
}
