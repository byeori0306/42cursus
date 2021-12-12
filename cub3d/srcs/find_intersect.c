/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:46:22 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/12 16:51:03 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	hit_wall(t_game *game, double x, double y)
{
	int	col;
	int row;

	if (x < 0 || x > (game->map_info.col * TILE_SIZE) || y < 0 || y > (game->map_info.row * TILE_SIZE))
		return (TRUE);
	col = (int)floor(x / TILE_SIZE);
	row = (int)floor(y / TILE_SIZE);
	if (col > game->map_info.col - 1 || row > game->map_info.row - 1)
		return (TRUE);
	if (game->map_info.map[row][col] == '1')
		return (TRUE);
	return (FALSE);
}

static void	find_intersect(t_game *game, t_temp_ray *temp_ray, int a, int b)
{
	double next_x;
	double next_y;
	
	next_x = temp_ray->first_x;
	next_y = temp_ray->first_y;
	while (!temp_ray->found_wall)
	{
		if (hit_wall(game, next_x + a, next_y + b))
		{
			temp_ray->found_wall = TRUE;
			temp_ray->intersect_x = next_x;
			temp_ray->intersect_y = next_y;
		}
		else
		{
			next_x += temp_ray->step_x;
			next_y += temp_ray->step_y;
		}
	}
}

static void	calculate_distance(t_game *game, t_temp_ray *temp_ray)
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;

	x1 = game->player.pos_x;
	y1 = game->player.pos_y;
	x2 = temp_ray->intersect_x;
	y2 = temp_ray->intersect_y;
	if (temp_ray->found_wall)
		temp_ray->distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	else
		temp_ray->distance = 1.7976931348623157E+308;
}

void	check_horz(t_game *game, t_temp_ray *horz)
{
	horz->intersect_x = 0;
	horz->intersect_y = 0;
	horz->found_wall = FALSE;
	
	horz->first_y = floor(game->player.pos_y / TILE_SIZE) * TILE_SIZE;
	if (game->ray.is_facing_down)
		horz->first_y += TILE_SIZE;
	horz->first_x = game->player.pos_x + (horz->first_y - game->player.pos_y) / tan(game->ray.ray_angle);
	
	horz->step_y = TILE_SIZE;
	if (game->ray.is_facing_up)
		horz->step_y *= -1;
	horz->step_x = TILE_SIZE / tan(game->ray.ray_angle);
	if (game->ray.is_facing_left && horz->step_x > 0)
		horz->step_x *= -1;
	else if (game->ray.is_facing_right && horz->step_x < 0)
		horz->step_x *= -1;
	if (game->ray.is_facing_up)
		find_intersect(game, horz, 0, -1);
	else
		find_intersect(game, horz, 0, 0);
	calculate_distance(game, horz);
}

void	check_vert(t_game *game, t_temp_ray *vert)
{
	vert->intersect_x = 0;
	vert->intersect_y = 0;
	vert->found_wall = FALSE;
	
	vert->first_x = floor(game->player.pos_x / TILE_SIZE) * TILE_SIZE;
	if (game->ray.is_facing_right)
		vert->first_x += TILE_SIZE;
	vert->first_y = game->player.pos_y + (vert->first_x - game->player.pos_x) * tan(game->ray.ray_angle);
	
	vert->step_x = TILE_SIZE;
	if (game->ray.is_facing_left)
		vert->step_x *= -1;
	vert->step_y = TILE_SIZE * tan(game->ray.ray_angle);
	if (game->ray.is_facing_up && vert->step_y > 0)
		vert->step_y *= -1;
	else if (game->ray.is_facing_down && vert->step_y < 0)
		vert->step_y *= -1;
	if (game->ray.is_facing_left)
		find_intersect(game, vert, -1, 0);
	else
		find_intersect(game, vert, 0, 0);
	calculate_distance(game, vert);
}