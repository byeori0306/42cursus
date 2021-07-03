/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 03:28:43 by dahpark           #+#    #+#             */
/*   Updated: 2021/06/24 10:39:01 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	check_file_type(char *file_name)
{
	char *dot;

	dot = ft_strrchr(file_name, '.');
	if (!dot)
		return (-1);
	return (ft_strncmp(dot, ".ber", 5));
}

void		check_argument(int argc, char *file_name)
{
	if (argc < 2)
		print_error("Program requires map(.ber) file.\n");
	else if (argc > 2)
		print_error("Too many arguments.\n");
	if (check_file_type(file_name))
		print_error("Invalid file type.\n");
}

void		check_screen_size(t_game *game)
{
	int screen_x;
	int screen_y;

	mlx_get_screen_size(game->mlx, &screen_x, &screen_y);
	if (TILE_SIZE * game->map_info.col > screen_x ||
	TILE_SIZE * game->map_info.row > screen_y)
	{
		free_map(&(game->map_info), game->map_info.row);
		print_error("Please resize the map.\n");
	}
}

void		print_error(char *message)
{
	ft_putstr_fd("Error\n", STD_ERR);
	ft_putstr_fd(message, STD_ERR);
	exit(EXIT_FAIL);
}
