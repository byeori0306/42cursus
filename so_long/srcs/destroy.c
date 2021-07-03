/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 05:58:16 by dahpark           #+#    #+#             */
/*   Updated: 2021/06/24 08:08:48 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_images(t_game *game, t_img *img)
{
	if (img->wall)
		mlx_destroy_image(game->mlx, img->wall);
	if (img->floor)
		mlx_destroy_image(game->mlx, img->floor);
	if (img->closed)
		mlx_destroy_image(game->mlx, img->closed);
	if (img->opened)
		mlx_destroy_image(game->mlx, img->opened);
	if (img->cherry)
		mlx_destroy_image(game->mlx, img->cherry);
	if (img->player_start)
		mlx_destroy_image(game->mlx, img->player_start);
	if (img->player_w)
		mlx_destroy_image(game->mlx, img->player_w);
	if (img->player_a)
		mlx_destroy_image(game->mlx, img->player_a);
	if (img->player_s)
		mlx_destroy_image(game->mlx, img->player_s);
	if (img->player_d)
		mlx_destroy_image(game->mlx, img->player_d);
}

void	destroy(t_game *game)
{
	if (game->map_info.map)
		free_map(&(game->map_info), game->map_info.row);
	destroy_images(game, &(game->img));
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
}
