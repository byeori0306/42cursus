/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 04:06:25 by dahpark           #+#    #+#             */
/*   Updated: 2021/06/24 08:09:15 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map_info(t_map_info *map_info)
{
	map_info->row = 0;
	map_info->col = 0;
	map_info->start_pos = 0;
	map_info->exit = 0;
	map_info->collectibles = 0;
}

void	init_game(t_game *game)
{
	check_screen_size(game);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(&(game->map_info), game->map_info.row);
		print_error("Can't start game.\n");
	}
	game->window = mlx_new_window(game->mlx, game->map_info.col * TILE_SIZE,
			game->map_info.row * TILE_SIZE, "so_long");
	if (!game->window)
	{
		free_map(&(game->map_info), game->map_info.row);
		print_error("Making window failed.\n");
	}
	game->end = FALSE;
}

void	init_player(t_player *p, int x, int y)
{
	p->cur_x = x;
	p->cur_y = y;
	p->next_x = x;
	p->next_y = y;
	p->movement = 0;
}

void	init_image(t_img *img)
{
	img->wall = NULL;
	img->floor = NULL;
	img->closed = NULL;
	img->opened = NULL;
	img->cherry = NULL;
	img->player_start = NULL;
	img->player_w = NULL;
	img->player_a = NULL;
	img->player_s = NULL;
	img->player_d = NULL;
}
