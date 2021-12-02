/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:29:45 by dahpark           #+#    #+#             */
/*   Updated: 2021/11/29 23:07:24 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_wall(t_game *game, int keycode, int x, int y)
{
	int cur_pixel;

	if (keycode == KEY_W || keycode == KEY_A)
		cur_pixel = x + y * (game->map_info.col + 1) * TILE_SIZE;
	else
		cur_pixel = (x + PL_SIZE / 2) + (y + PL_SIZE / 2) * (game->map_info.col + 1) * TILE_SIZE;
	if (game->img.data[cur_pixel] == WHITE)
		return (1);
	return (0);
}

static void	rotate(t_player *player, double angle)
{
	double old_dir_x;
	
	old_dir_x = player->dir_x;
	player->dir_x = cos(angle) * player->dir_x - sin(angle) * player->dir_y;
	player->dir_y = sin(angle) * player->dir_x + cos(angle) * player->dir_y;	
}

static void	change_player_pos(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos_x;
	y = game->player.pos_y;
	if (keycode == KEY_W)
	{
		x += game->player.dir_x;
		y += game->player.dir_y;
	}
	else if (keycode == KEY_A)
		rotate(&game->player, M_PI/36);
	else if (keycode == KEY_S)
	{
		x -= game->player.dir_x;
		y -= game->player.dir_y;
	}
	else if (keycode == KEY_D)
		rotate(&game->player, -M_PI/36);
	if (is_wall(game, keycode, x, y))
		return ;
	else
	{
		game->player.pos_x = x;
		game->player.pos_y = y;
	}
}

int	move(int keycode, t_game *game)
{
	change_player_pos(keycode, game);
	return (0);
}
