/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:55:59 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/06 18:32:53 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_info(t_game *game)
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

void	init_player(t_player *pl, char dir)
{
	pl->turn_dir = 0;
	pl->walk_dir = 0;
	if (dir == 'N')
		pl->rotation_angle = 1.5 * M_PI;
	else if (dir == 'S')
		pl->rotation_angle = 0.5 * M_PI;
	else if (dir == 'W')
		pl->rotation_angle = M_PI;
	else if (dir == 'E')
		pl->rotation_angle = 0;
	pl->walk_speed = 2;
	pl->turn_speed = 3 * (M_PI / 180);
}

void	init_map(t_map_info *map_info)
{
	int	row;
	int	col;
	int	i;

	i = 0;
	row = map_info->row + 2;
	col = map_info->col + 2;
	map_info->map = malloc(sizeof(char *) * (row + 1));
	if (!map_info->map)
		strerror(ENOMEM);
	while (i < row + 1)
	{
		map_info->map[i] = malloc(sizeof(char) * (col + 1));
		if (!map_info->map[i])
			strerror(ENOMEM);
		ft_memset(map_info->map[i], ' ', col);
		map_info->map[i][col] = '\0';
		i++;
	}
	map_info->map[row + 1] = NULL;
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		print_err("Can't start game.\n");
	game->window = mlx_new_window(game->mlx,
			WIDTH,
			HEIGHT, "cub3d");
	if (!game->window)
		print_err("Making window failed.\n");
	game->img.img_ptr = mlx_new_image(game->mlx,
			WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr,
			&game->img.bpp, &game->img.size_line, &game->img.endian);
}
