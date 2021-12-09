/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:53:35 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/09 17:37:36 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_render(t_game *game, t_render *render)
{
	render->correct_dist = game->ray.distance * cos(game->ray.ray_angle - game->player.rotation_angle);
	render->dist_to_plane = (WIDTH / 2) / tan(FOV / 2);
	render->projected_wall_height = (int)((TILE_SIZE / render->correct_dist) * render->dist_to_plane);

	render->top = (HEIGHT / 2) - (render->projected_wall_height / 2);
	if (render->top < 0)
		render->top = 0;
	render->bottom = (HEIGHT / 2) + (render->projected_wall_height / 2);
	if (render->bottom > HEIGHT)
		render->bottom = HEIGHT;
}

static void	paint_sky(t_game *game, int column_id, int top)
{
	int y;

	y = 0;
	while (y < top)
	{
		game->img.data[WIDTH * y + column_id] = game->elem_info.c;
		y++;
	}
}

static void	paint_ground(t_game *game, int column_id, int bottom)
{
	int y;

	y = bottom;
	while (y < HEIGHT)
	{
		game->img.data[WIDTH * y + column_id] = game->elem_info.f;
		y++;		
	}	
}

static void	paint_wall(t_game *game, int column_id)
{
	int y;
	int wall_height;

	y = game->render.top;
	wall_height = game->render.bottom - game->render.top;
	// while (y < game->render.bottom)
	// {
	// 	game->img.data[WIDTH * y + column_id] = 0x0000FF00;
	// 	y++;
	// }

	int tex_pos_x;
	int tex_pos_y;
	if (game->ray.hit_vertical)
		tex_pos_x = fmod(game->ray.intersect_y, TILE_SIZE) / TILE_SIZE * TEX_SIZE;
	else
		tex_pos_x = fmod(game->ray.intersect_x, TILE_SIZE) / TILE_SIZE * TEX_SIZE;
	while (y < game->render.bottom)
	{
		tex_pos_y = (y - (HEIGHT / 2 - game->render.projected_wall_height / 2)) * TEX_SIZE / game->render.projected_wall_height;
		game->img.data[WIDTH * y + column_id] = game->elem_info.ptr[TEX_SIZE * tex_pos_y + tex_pos_x];
		y++;
	}
}

void	render_col(t_game *game, int column_id)
{
	init_render(game, &game->render);

	paint_wall(game, column_id);
	paint_sky(game, column_id, game->render.top);
	paint_ground(game, column_id, game->render.bottom);
}