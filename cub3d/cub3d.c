/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:06:44 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/14 14:48:24 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_game(t_game *game, int argc, char **argv)
{
	check_arg(argc, argv);
	init_info(game);
	init_window(game);
	check_file(game, argv[1]);
	get_map(game, &(game->map_info), argv[1]);
	check_map(game, &(game->map_info));
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game, argc, argv);
	mlx_hook(game.window, DESTROY_NOTIFY, 0, &close_window, &game);
	mlx_hook(game.window, KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.window, KEY_RELEASE, 0, &key_release, &game);
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_loop(game.mlx);
	return (0);
}
