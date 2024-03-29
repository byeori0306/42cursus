/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:29:45 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/12 16:40:46 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_wall(t_game *game, double x, double y)
{
	int	col;
	int row;

	col = (int)floor(x);
	row = (int)floor(y);
	col /= TILE_SIZE;
	row /= TILE_SIZE;
	if (game->map_info.map[row][col] == '1')
		return (TRUE);
	return (FALSE);
}

static void	change_player_dir(int keycode, t_player *pl)
{
	if (keycode == KEY_W)
		pl->walk_dir = 1;
	else if (keycode == KEY_S)
		pl->walk_dir = -1;
	else if (keycode == KEY_A || keycode == KEY_D)
		pl->walk_dir = 1;
	else if (keycode == KEY_LEFT)
		pl->turn_dir = -1;
	else if (keycode == KEY_RIGHT)
		pl->turn_dir = 1;
}

int	change_player_pos(int keycode, t_game *game, t_player *pl)
{
	double	move_step;
	double	move_angle;
	double	new_pos_x;
	double	new_pos_y;
	
	change_player_dir(keycode, pl);
	pl->rotation_angle += pl->turn_dir * pl->turn_speed;
	move_step = pl->walk_dir * pl->walk_speed;
	if (keycode == KEY_A)
		move_angle = -M_PI / 2;
	else if (keycode == KEY_D)
		move_angle = M_PI / 2;
	else
		move_angle = 0;
	new_pos_x = pl->pos_x + cos(pl->rotation_angle + move_angle) * move_step;
	new_pos_y = pl->pos_y + sin(pl->rotation_angle + move_angle) * move_step;
	if (!is_wall(game, new_pos_x, new_pos_y))
	{
		pl->pos_x = new_pos_x;
		pl->pos_y = new_pos_y;
	}
	return (0);
}

void reset_player_dir(int keycode, t_player *pl)
{
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)
		pl->walk_dir = 0;
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		pl->turn_dir = 0;
}