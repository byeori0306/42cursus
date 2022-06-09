/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_changes_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 04:08:55 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/07 07:54:43 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static	void	check_num_movement(t_game *game)
{
	if (game->player.movement == INT_MAX)
	{
		game->end = TRUE;
		ft_putstr_fd("Too many movement. Please retry game.\n", STD_OUT);
		return ;
	}
	return ;
}

static	void	reflect_changes(t_game *game)
{
	t_player py;

	py = game->player;
	if (check_cur_pos('C', game) == TRUE)
	{
		game->map_info.collectibles--;
		game->map_info.map[py.cur_y][py.cur_x] = '0';
	}
	else if (check_cur_pos('G', game) == TRUE)
	{
		put_image(game, game->img.end, py.cur_x, py.cur_y);
		game->end = TRUE;
	}
	else if (check_cur_pos('E', game) == TRUE
	&& game->map_info.collectibles == 0)
	{
		put_image(game, game->img.opened, py.cur_x, py.cur_y);
		game->end = TRUE;
	}
}

int				check_cur_pos(char component, t_game *game)
{
	int x;
	int y;

	x = game->player.cur_x;
	y = game->player.cur_y;
	if (game->map_info.map[y][x] == component)
		return (TRUE);
	else
		return (FALSE);
}

int				check_next_pos(char component, t_game *game)
{
	int x;
	int y;

	x = game->player.next_x;
	y = game->player.next_y;
	if (game->map_info.map[y][x] == component)
		return (TRUE);
	else
		return (FALSE);
}

int				handle_changes(int keycode, t_game *game, t_player *py)
{
	check_num_movement(game);
	if (game->end == TRUE)
		return (0);
	if (check_cur_pos('E', game) == TRUE)
		put_image(game, game->img.closed, py->cur_x, py->cur_y);
	else
		put_image(game, game->img.floor, py->next_x, py->next_y);
	py->key = keycode;
	find_next_pos(keycode, game);
	set_cur_pos(py);
	reflect_changes(game);
	return (0);
}
