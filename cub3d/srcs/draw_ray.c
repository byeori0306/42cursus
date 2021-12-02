/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:09:05 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/01 21:17:47 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// static void	draw_line(t_game *game, double angle)
// {
// 	double	ray_x;
// 	double	ray_y;
// 	double	dx;
// 	double	dy;
// 	double	max_value;

// 	ray_x = game->player.pos_x;
// 	ray_y = game->player.pos_y;

// 	dx = cos(angle) * game->player.dir_x - sin(angle) * game->player.dir_y;
// 	dy = sin(angle) * game->player.dir_x + cos(angle) * game->player.dir_y;

// 	max_value = fmax(fabs(dx), fabs(dy));
// 	dx /= max_value;
// 	dy /= max_value;
	
// 	while (1)
// 	{
// 		if (game->img.data[(game->map_info.col + 1) * TILE_SIZE * (int)floor(ray_y) + (int)floor(ray_x)] != WHITE)
// 			game->img.data[(game->map_info.col + 1) * TILE_SIZE * (int)floor(ray_y) + (int)floor(ray_x)] = YELLOW;
// 		else
// 			break;
// 		ray_x += dx;
// 		ray_y += dy;
// 	}
// }

static void	init_ray(t_ray *ray, double angle)
{
	ray->angle = angle;
	ray->intersect_x = 0;
	ray->intersect_y = 0;
	ray->distance = 0;
	ray->hit_vertical = 0;
}

static void	check_intersect()
{
	
}

static double	cal_distance(t_temp_ray *ray)
{
	
}

static void	check_horizontal_intersection(t_game *game, t_temp_ray *horz)
{
	horz->is_wall = 0;
	horz->intersect_x = 0;
	horz->intersect_y = 0;
	
	horz->first_y = (int)floor(game->player.pos_y / TILE_SIZE) * TILE_SIZE;
	// if facing down -> += TILE_SIZE
	
	horz->first_x = game->player.pos_x + (horz->first_y - game->player.pos_y / tan(game->ray.angle));
	
	horz->step_y = TILE_SIZE;
	// if facing up -. *= -1 or 1

	horz->step_x = TILE_SIZE / tan(game->ray.angle);
	
	check_intersect();
	cal_distance();
}

static void	check_vertical_intersection(t_temp_ray *vert)
{
	check_intersect();
	cal_distance();
}

static void	draw_ray(t_game *game, double angle)
{
	t_temp_ray	horz;
	t_temp_ray	vert;

	init_ray(&game->ray, angle);
	check_horizontal_intersection(game, &horz);
	check_vertical_intersection(&vert);
	if (horz.distance > vert.distance)
	{
		game->ray.intersect_x = horz.intersect_x;
		game->ray.intersect_y = horz.intersect_y;
		game->ray.distance = horz.distance;
		game->ray.hit_vertical = 0;
	}
	else
	{
		game->ray.intersect_x = vert.intersect_x;
		game->ray.intersect_y = vert.intersect_y;
		game->ray.distance = vert.distance;
		game->ray.hit_vertical = 1;
	}
	// draw_line
}

void	draw_rays(t_game *game)
{
	double	angle;
	double	increment;

	angle = 0;
	increment = (FOV / 2) / (TILE_SIZE * game->map_info.col);
	while (angle <= FOV / 2)
	{
		draw_ray(game, angle);
		draw_ray(game, -angle);
		angle += increment;
	}
}