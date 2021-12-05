/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:52:11 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/04 14:10:12 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_map_components(t_game *game, char ch, int cur_col)
{
	if (ch == ' ' || ch == '0' || ch == '1')
		return (1);
	else if (ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
	{
		if (game->player.pos_x > 0 || game->player.pos_y > 0)
			print_err("Invalid map : multiple player's start position");
		game->player.pos_x = cur_col * TILE_SIZE
			+ ((TILE_SIZE - PL_SIZE) / 2);
		game->player.pos_y = game->map_info.row * TILE_SIZE
			+ ((TILE_SIZE - PL_SIZE) / 2);
		init_player(&(game->player), ch);
		return (1);
	}
	return (0);
}

void	get_map_info(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!is_map_components(game, line[i], i))
			print_err("Invalid map : invalid map components");
		i++;
	}
	if (i > game->map_info.col)
		game->map_info.col = i;
	game->map_info.row += 1;
}
