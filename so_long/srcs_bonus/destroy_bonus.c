/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 05:58:16 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/07 07:55:35 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static	void	destroy_images(t_game *game, t_img *img)
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
	if (img->start)
		mlx_destroy_image(game->mlx, img->start);
	if (img->end)
		mlx_destroy_image(game->mlx, img->end);
	if (img->enemy_1)
		mlx_destroy_image(game->mlx, img->enemy_1);
	if (img->enemy_2)
		mlx_destroy_image(game->mlx, img->enemy_2);
}

static	void	destroy_player_images(t_game *game, t_img *img)
{
	if (img->p_w_1)
		mlx_destroy_image(game->mlx, img->p_w_1);
	if (img->p_w_2)
		mlx_destroy_image(game->mlx, img->p_w_2);
	if (img->p_a_1)
		mlx_destroy_image(game->mlx, img->p_a_1);
	if (img->p_a_2)
		mlx_destroy_image(game->mlx, img->p_a_2);
	if (img->p_s_1)
		mlx_destroy_image(game->mlx, img->p_s_1);
	if (img->p_s_2)
		mlx_destroy_image(game->mlx, img->p_s_2);
	if (img->p_d_1)
		mlx_destroy_image(game->mlx, img->p_d_1);
	if (img->p_d_2)
		mlx_destroy_image(game->mlx, img->p_d_2);
}

void			destroy(t_game *game)
{
	if (game->map_info.map)
		free_map(&(game->map_info), game->map_info.row);
	destroy_images(game, &(game->img));
	destroy_player_images(game, &(game->img));
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
}
