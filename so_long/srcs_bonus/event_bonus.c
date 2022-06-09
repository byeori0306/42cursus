/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 02:56:56 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/07 11:17:45 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static	void	set_flag(t_game *game)
{
	if (game->flag == 1)
		game->flag = 2;
	else if (game->flag == 2)
		game->flag = 1;
}

int				close_window(t_game *game)
{
	destroy(game);
	exit(EXIT_OK);
	return (0);
}

int				key_press_event(int keycode, t_game *game)
{
	if (keycode == ESC)
		return (close_window(game));
	else if (keycode == KEY_W || keycode == KEY_A ||
			keycode == KEY_S || keycode == KEY_D)
	{
		game->start = TRUE;
		return (handle_changes(keycode, game, &(game->player)));
	}
	return (0);
}

int				animate(t_game *game)
{
	if (game->start == TRUE && game->end == FALSE)
		animate_player(game);
	game->cnt++;
	if (game->cnt % DURATION == 0)
	{
		game->cnt = 0;
		set_flag(game);
	}
	return (0);
}
