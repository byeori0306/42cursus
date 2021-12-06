/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:34:38 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/06 18:57:08 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// static void	draw_player(t_game *game)
// {
// 	int	x;
// 	int	y;
// 	int start_x;
// 	int start_y;

// 	x = (int)floor(game->player.pos_x);
// 	y = (int)floor(game->player.pos_y);
// 	start_x = x;
// 	start_y = y;
// 	while (y < start_y + PL_SIZE)
// 	{
// 		x = start_x;
// 		while (x < start_x + PL_SIZE)
// 		{
// 			game->img.data[x + y * (game->map_info.col + 1) * TILE_SIZE] = 0x00FF0000;
// 			x++;
// 		}
// 		y++;
// 	}
// }

// static void	draw_tile(t_game *game, int x, int y, int color)
// {
// 	int	dx;
// 	int	dy;

// 	x *= TILE_SIZE;
// 	y *= TILE_SIZE;
// 	dy = 0;
// 	while (dy < TILE_SIZE)
// 	{
// 		dx = 0;
// 		while (dx < TILE_SIZE)
// 		{
// 			game->img.data[(x + dx) + (y + dy) * (game->map_info.col + 1) * TILE_SIZE] = color;
// 			dx++;
// 		}
// 		dy++;
// 	}
// }

// int	draw_mini_map(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (y < game->map_info.row)
// 	{
// 		x = 0;
// 		while (x < game->map_info.col)
// 		{
// 			if (game->map_info.map[y][x] == '1')
// 				draw_tile(game, x, y, WHITE);
// 			else
// 				draw_tile(game, x, y, BLACK);
// 			x++;
// 		}
// 		y++;
// 	}
// 	draw_player(game);
// 	draw_rays(game);
// 	mlx_put_image_to_window(game->mlx, game->window, game->img.img_ptr, 0, 0);
// 	return (0);
// }

int	render(t_game *game)
{
	draw_rays(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img_ptr, 0, 0);
	return (0);
}