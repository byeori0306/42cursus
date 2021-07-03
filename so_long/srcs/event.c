/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 02:56:56 by dahpark           #+#    #+#             */
/*   Updated: 2021/06/24 10:39:43 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_game *game)
{
	destroy(game);
	exit(EXIT_OK);
	return (0);
}

int	key_press_event(int keycode, t_game *game)
{
	if (keycode == ESC)
		return (close_window(game));
	else if (keycode == KEY_W || keycode == KEY_A ||
			keycode == KEY_S || keycode == KEY_D)
		return (handle_changes(keycode, game, game->img, &(game->player)));
	return (0);
}
