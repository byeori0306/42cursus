/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:53:35 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/06 19:42:30 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	paint_sky(t_game *game, int column_id, int top)
{
	int y;

	y = 0;
	while (y < top)
	{
		game->img.data[WIDTH * y + column_id] = 0x000000FF;
		y++;
	}
}

static void	paint_ground(t_game *game, int column_id, int bottom)
{
	int y;

	y = bottom;
	while (y < HEIGHT)
	{
		game->img.data[WIDTH * y + column_id] = 0x00000000;
		y++;		
	}	
}

void	render_walls(t_game *game, int column_id)
{
	int top;
	int	bottom;
	double dist_to_plane;
	int projected_wall_height;

	dist_to_plane = (WIDTH / 2) / tan(FOV / 2);
	projected_wall_height = (int)((TILE_SIZE / game->ray.distance) * dist_to_plane);

	top = (HEIGHT / 2) - (projected_wall_height / 2);
	bottom = (HEIGHT / 2) + (projected_wall_height / 2);

	int y;

	y = top;
	while (y < bottom)
	{
		game->img.data[WIDTH * y + column_id] = 0x0000FF00;
		y++;
	}
	paint_sky(game, column_id, top);
	paint_ground(game, column_id, bottom);
}