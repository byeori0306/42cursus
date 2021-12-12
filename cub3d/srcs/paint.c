/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:33:56 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/12 16:36:37 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	*find_wall_img(t_game *game)
{
	if (game->render.dir == NO)
		return (game->elem_info.no);
	else if (game->render.dir == SO)
		return (game->elem_info.so);
	else if (game->render.dir == WE)
		return (game->elem_info.we);
	else
		return (game->elem_info.ea);	
}

void	paint_wall(t_game *game, int column_id)
{
	int y;
	int wall_height;
	int *wall;

	y = game->render.top;
	wall_height = game->render.bottom - game->render.top;
	wall = find_wall_img(game);

	int tex_pos_x;
	int tex_pos_y;
	if (game->ray.hit_vertical)
		tex_pos_x = fmod(game->ray.intersect_y, TILE_SIZE) / TILE_SIZE * TEX_SIZE;
	else
		tex_pos_x = fmod(game->ray.intersect_x, TILE_SIZE) / TILE_SIZE * TEX_SIZE;
	while (y < game->render.bottom)
	{
		tex_pos_y = (y - (HEIGHT / 2 - game->render.projected_wall_height / 2)) * TEX_SIZE / game->render.projected_wall_height;
		game->img.data[WIDTH * y + column_id] = wall[TEX_SIZE * tex_pos_y + tex_pos_x];
		y++;
	}
}

void	paint_sky(t_game *game, int column_id, int top)
{
	int y;

	y = 0;
	while (y < top)
	{
		game->img.data[WIDTH * y + column_id] = game->elem_info.c;
		y++;
	}
}

void	paint_ground(t_game *game, int column_id, int bottom)
{
	int y;

	y = bottom;
	while (y < HEIGHT)
	{
		game->img.data[WIDTH * y + column_id] = game->elem_info.f;
		y++;		
	}	
}