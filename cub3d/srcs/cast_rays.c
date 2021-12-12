/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:09:05 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/12 16:50:51 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static double normalize_angle(double angle)
{
	if (angle >= 0)
	{
		while (angle >= 2 * M_PI)
			angle -= 2 * M_PI;
	}
	else
	{
		while (angle <= 0)
			angle += 2 * M_PI;
	}
	return (angle);
}

static void	init_ray(t_ray *ray, double angle)
{
	ray->ray_angle = normalize_angle(angle);
	ray->intersect_x = 0;
	ray->intersect_y = 0;
	ray->distance = 0;
	if (ray->ray_angle > 0 && ray->ray_angle < M_PI)
		ray->is_facing_down = TRUE;
	else
		ray->is_facing_down = FALSE;
	ray->is_facing_up = !ray->is_facing_down;
	if (ray->ray_angle < 0.5 * M_PI || ray->ray_angle > 1.5 * M_PI)
		ray->is_facing_right = TRUE;
	else
		ray->is_facing_right = FALSE;
	ray->is_facing_left = !ray->is_facing_right;
}

static void	cast_ray(t_game *game, double angle)
{
	t_temp_ray	horz;
	t_temp_ray	vert;

	init_ray(&game->ray, angle);
	check_horz(game, &horz);
	check_vert(game, &vert);
	if (horz.distance > vert.distance)
	{
		game->ray.intersect_x = vert.intersect_x;
		game->ray.intersect_y = vert.intersect_y;
		game->ray.distance = vert.distance;
		game->ray.hit_vertical = TRUE;
	}
	else
	{
		game->ray.intersect_x = horz.intersect_x;
		game->ray.intersect_y = horz.intersect_y;
		game->ray.distance = horz.distance;
		game->ray.hit_vertical = FALSE;
	}
}

void	cast_rays(t_game *game)
{
	int		col_id;
	double	ray_angle;
	double	increment;

	col_id = 0;
	ray_angle = game->player.rotation_angle - (FOV / 2);
	increment = FOV / WIDTH;
	while (col_id < WIDTH)
	{
		cast_ray(game, ray_angle);
		render_col(game, col_id);
		ray_angle += increment;
		col_id++;
	}
}