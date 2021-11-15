/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:42:03 by dahpark           #+#    #+#             */
/*   Updated: 2021/11/09 16:45:19 by dahpark          ###   ########seoul.kr  */
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
	return (0);
}