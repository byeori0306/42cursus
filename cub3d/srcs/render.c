/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:53:35 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/12 16:44:15 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	find_direction(t_game *game)
{
	if (game->ray.hit_vertical == FALSE && (game->player.pos_y - game->ray.intersect_y) > 0)
		return (NO);
	else if (game->ray.hit_vertical == FALSE && (game->player.pos_y - game->ray.intersect_y) < 0)
		return (SO);
	else if (game->ray.hit_vertical == TRUE && (game->player.pos_x - game->ray.intersect_x) > 0)
		return (WE);
	else
		return (EA);
}

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
	render->dir = find_direction(game);
}

void	render_col(t_game *game, int column_id)
{
	init_render(game, &game->render);
	paint_wall(game, column_id);
	paint_sky(game, column_id, game->render.top);
	paint_ground(game, column_id, game->render.bottom);
}

int	render(t_game *game)
{
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img_ptr, 0, 0);
	return (0);
}