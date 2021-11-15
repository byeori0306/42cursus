/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:55:59 by dahpark           #+#    #+#             */
/*   Updated: 2021/11/13 20:00:59 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    init_info(t_game *game)
{
    game->map_info.row = 0;
    game->map_info.col = 0;
	game->map_info.start_pos = 0;
	game->map_info.start_line = 0;
	game->map_info.map = NULL;
	game->elem_info.no = NULL;
	game->elem_info.so = NULL;
	game->elem_info.we = NULL;
	game->elem_info.ea = NULL;
	game->elem_info.f = NULL;
	game->elem_info.c = NULL;
	game->player.pos_x = 0;
	game->player.pos_y = 0;
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		print_err("Can't start game.\n");
	game->window = mlx_new_window(game->mlx, game->map_info.col * TILE_SIZE,
			game->map_info.row * TILE_SIZE, "cub3d");
	if (!game->window)
		print_err("Making window failed.\n");
}