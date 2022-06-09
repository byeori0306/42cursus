/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ghost_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:27:26 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/07 07:57:07 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static	int		set_ghost_num(t_map_info *m)
{
	return ((m->space) / 10 + 1);
}

static	int		find_in_odd_row(t_map_info *m, int row)
{
	int col;

	col = 1;
	while (col < m->col)
	{
		if (m->map[row][col] == '0')
		{
			m->map[row][col] = 'G';
			return (TRUE);
		}
		col++;
	}
	return (FALSE);
}

static	int		find_in_even_row(t_map_info *m, int row)
{
	int col;

	col = m->col - 2;
	while (col > 0)
	{
		if (m->map[row][col] == '0')
		{
			m->map[row][col] = 'G';
			return (TRUE);
		}
		col--;
	}
	return (FALSE);
}

static	void	choose_ghost_pos(t_map_info *m, int row)
{
	while (row < m->row)
	{
		if (row % 2 == 0)
		{
			if (find_in_odd_row(m, row) == TRUE)
				break ;
		}
		else if (row % 2 == 1)
		{
			if (find_in_even_row(m, row) == TRUE)
				break ;
		}
		row++;
	}
}

void			add_ghost(t_map_info *m)
{
	int	cnt;
	int	row;

	if (m->space < 10)
		return ;
	cnt = 0;
	row = 1;
	m->ghost = set_ghost_num(m);
	while (cnt <= m->ghost)
	{
		if (row == m->row)
			row = 1;
		choose_ghost_pos(m, row);
		cnt++;
		row++;
	}
}
