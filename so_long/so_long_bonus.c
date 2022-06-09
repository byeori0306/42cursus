/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 02:56:56 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/07 10:31:15 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int				main(int argc, char **argv)
{
	t_game	game;

	check_argument(argc, argv[1]);
	init_map_info(&game.map_info);
	check_map(argv[1], &game.map_info);
	get_map(argv[1], &game.map_info);
	add_ghost(&game.map_info);
	init_game(&game);
	draw_map(&game);
	mlx_hook(game.window, DESTROY_NOTIFY, 0, &close_window, &game);
	mlx_hook(game.window, KEY_PRESS, 0, &key_press_event, &game);
	mlx_loop_hook(game.mlx, &animate, &game);
	mlx_loop(game.mlx);
}
