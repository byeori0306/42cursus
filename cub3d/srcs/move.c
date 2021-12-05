/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:29:45 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/05 16:52:50 by dahpark          ###   ########seoul.kr  */
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
	{
		pl->turn_dir = 0;
		pl->walk_dir = 1;
	}
	else if (keycode == KEY_S)
	{
		pl->turn_dir = 0;
		pl->walk_dir = -1;
	}
	else if (keycode == KEY_A)
	{
		pl->turn_dir = -1;
		pl->walk_dir = 0;
	}
	else if (keycode == KEY_D)
	{
		pl->turn_dir = 1;
		pl->walk_dir = 0;
	}
}

// update player position based on turn direction and walk direction
static void	change_player_pos(int keycode, t_game *game, t_player *pl)
{
	double	move_step;
	double	new_pos_x;
	double	new_pos_y;
	
	change_player_dir(keycode, pl);
	pl->rotation_angle += pl->turn_dir * pl->turn_speed;
	move_step = pl->walk_dir * pl->walk_speed;
	new_pos_x = pl->pos_x + cos(pl->rotation_angle) * move_step;
	new_pos_y = pl->pos_y + sin(pl->rotation_angle) * move_step;
	if (!is_wall(game, new_pos_x, new_pos_y))
	{
		pl->pos_x = new_pos_x;
		pl->pos_y = new_pos_y;
	}
}

int	move(int keycode, t_game *game)
{
	change_player_pos(keycode, game, &game->player);
	return (0);
}
