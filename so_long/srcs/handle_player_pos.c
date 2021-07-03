/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_player_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 04:08:35 by dahpark           #+#    #+#             */
/*   Updated: 2021/06/24 08:09:10 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	print_num_movement(t_player *p)
{
	p->movement++;
	ft_putnbr_fd(p->movement, 1);
	ft_putstr_fd("\n", 1);
}

static	void	cal_next_pos(t_player *p, int x, int y)
{
	if (x == 1)
		p->next_x++;
	else if (x == -1)
		p->next_x--;
	else if (y == 1)
		p->next_y++;
	else if (y == -1)
		p->next_y--;
}

static	void	do_not_move(t_player *p)
{
	p->next_x = p->cur_x;
	p->next_y = p->cur_y;
}

void			set_cur_pos(t_player *p)
{
	p->cur_x = p->next_x;
	p->cur_y = p->next_y;
}

void			find_next_pos(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		cal_next_pos(&(game->player), 0, -1);
	else if (keycode == KEY_A)
		cal_next_pos(&(game->player), -1, 0);
	else if (keycode == KEY_S)
		cal_next_pos(&(game->player), 0, 1);
	else if (keycode == KEY_D)
		cal_next_pos(&(game->player), 1, 0);
	if (check_next_pos('1', game) == TRUE)
		do_not_move(&(game->player));
	else
		print_num_movement(&(game->player));
}
