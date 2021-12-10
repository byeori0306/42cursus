/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:42:03 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/10 20:15:34 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	close_window(t_game *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		return (close_window(game));
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		return (move(keycode, game)); // player 좌표 바꾸기
	return (0);
}

int key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		reset(keycode, &game->player);
	return (0);
}