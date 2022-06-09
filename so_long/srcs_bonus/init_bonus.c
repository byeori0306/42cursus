/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 04:06:25 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/07 10:59:54 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_map_info(t_map_info *map_info)
{
	map_info->row = 0;
	map_info->col = 0;
	map_info->start_pos = 0;
	map_info->exit = 0;
	map_info->collectibles = 0;
	map_info->space = 0;
	map_info->ghost = 0;
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
	game->start = FALSE;
	game->end = FALSE;
	game->cnt = 0;
	game->flag = 1;
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
	img->start = NULL;
	img->end = NULL;
	img->p_w_1 = NULL;
	img->p_w_2 = NULL;
	img->p_a_1 = NULL;
	img->p_a_2 = NULL;
	img->p_s_1 = NULL;
	img->p_s_2 = NULL;
	img->p_d_1 = NULL;
	img->p_d_2 = NULL;
	img->enemy_1 = NULL;
	img->enemy_2 = NULL;
}
