/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:09:05 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/06 19:15:36 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	hit_wall(t_game *game, double x, double y)
{
	int	col;
	int row;

	if (x < 0 || x > (game->map_info.col * TILE_SIZE) || y < 0 || y > (game->map_info.row * TILE_SIZE))
		return (TRUE);
	col = (int)floor(x);
	row = (int)floor(y);
	col /= TILE_SIZE;
	row /= TILE_SIZE;
	if (game->map_info.map[row][col] == '1')
		return (TRUE);
	return (FALSE);
}

// static void	draw_line(t_game *game, t_player *pl, t_ray *ray)
// {
// 	double	ray_x;
// 	double	ray_y;
// 	double	dx;
// 	double	dy;
// 	double	max_value;

// 	ray_x = pl->pos_x;
// 	ray_y = pl->pos_y;

// 	dx = ray->intersect_x - pl->pos_x;
// 	dy = ray->intersect_y - pl->pos_y;

// 	max_value = fmax(fabs(dx), fabs(dy));
// 	dx /= max_value;
// 	dy /= max_value;
	
// 	while (TRUE)
// 	{
// 		if (hit_wall(game, ray_x, ray_y))
// 			break;
// 		else
// 			game->img.data[(game->map_info.col + 1) * TILE_SIZE * (int)floor(ray_y) + (int)floor(ray_x)] = YELLOW;
// 		ray_x += dx;
// 		ray_y += dy;
// 	}
// }

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

static void	find_intersect(t_game *game, t_temp_ray *temp_ray)
{
	double next_x;
	double next_y;
	
	next_x = temp_ray->first_x;
	next_y = temp_ray->first_y;
	while (!temp_ray->found_wall)
	{
		if (hit_wall(game, next_x, next_y))
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

static void	check_horz(t_game *game, t_temp_ray *horz)
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
	find_intersect(game, horz);
	calculate_distance(game, horz);
}

static void	check_vert(t_game *game, t_temp_ray *vert)
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
	find_intersect(game, vert);
	calculate_distance(game, vert);
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
		game->ray.intersect_x = horz.intersect_x;
		game->ray.intersect_y = horz.intersect_y;
		game->ray.distance = horz.distance;
	}
	else
	{
		game->ray.intersect_x = vert.intersect_x;
		game->ray.intersect_y = vert.intersect_y;
		game->ray.distance = vert.distance;
	}
	//draw_line(game, &game->player, &game->ray);
}

void	draw_rays(t_game *game)
{
	int		col_id;
	//int		width;
	double	ray_angle;
	double	increment;

	col_id = 0;
	//width = TILE_SIZE * game->map_info.col;
	ray_angle = game->player.rotation_angle - (FOV / 2);
	increment = FOV / WIDTH;
	while (col_id < WIDTH)
	{
		cast_ray(game, ray_angle);
		render_walls(game, col_id);
		ray_angle += increment;
		col_id++;
	}
}