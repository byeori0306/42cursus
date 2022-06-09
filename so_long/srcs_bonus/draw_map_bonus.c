/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 03:32:46 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/07 08:12:49 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static	void	*get_image(t_game *game, char *file)
{
	int		tile_size;
	void	*image;

	tile_size = TILE_SIZE;
	image = mlx_png_file_to_image(game->mlx, file, &tile_size, &tile_size);
	if (!image)
	{
		destroy(game);
		print_error("Load image failed.\n");
	}
	return (image);
}

static	void	get_images(t_game *game, t_img *img)
{
	init_image(&(game->img));
	img->wall = get_image(game, "./img_bonus/wall.png");
	img->floor = get_image(game, "./img_bonus/floor.png");
	img->closed = get_image(game, "./img_bonus/closed.png");
	img->opened = get_image(game, "./img_bonus/opened.png");
	img->cherry = get_image(game, "./img_bonus/cherry.png");
	img->start = get_image(game, "./img_bonus/start.png");
	img->end = get_image(game, "./img_bonus/end.png");
	img->p_w_1 = get_image(game, "./img_bonus/p_w_1.png");
	img->p_w_2 = get_image(game, "./img_bonus/p_w_2.png");
	img->p_a_1 = get_image(game, "./img_bonus/p_a_1.png");
	img->p_a_2 = get_image(game, "./img_bonus/p_a_2.png");
	img->p_s_1 = get_image(game, "./img_bonus/p_s_1.png");
	img->p_s_2 = get_image(game, "./img_bonus/p_s_2.png");
	img->p_d_1 = get_image(game, "./img_bonus/p_d_1.png");
	img->p_d_2 = get_image(game, "./img_bonus/p_d_2.png");
	img->enemy_1 = get_image(game, "./img_bonus/enemy_1.png");
	img->enemy_2 = get_image(game, "./img_bonus/enemy_2.png");
}

static	void	put_images(t_game *game, t_img img, int x, int y)
{
	t_map_info m;

	m = game->map_info;
	if (m.map[y][x] == '0')
		put_image(game, img.floor, x, y);
	else if (m.map[y][x] == '1')
		put_image(game, img.wall, x, y);
	if (m.map[y][x] == 'P')
	{
		put_image(game, img.start, x, y);
		init_player(&(game->player), x, y);
	}
	else if (m.map[y][x] == 'E')
		put_image(game, img.closed, x, y);
	else if (m.map[y][x] == 'C')
		put_image(game, img.cherry, x, y);
	else if (m.map[y][x] == 'G')
		put_image(game, img.enemy_2, x, y);
}

void			put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img,
	TILE_SIZE * x, TILE_SIZE * y);
}

void			draw_map(t_game *game)
{
	t_map_info	m;
	int			row;
	int			col;

	get_images(game, &(game->img));
	m = game->map_info;
	row = 0;
	while (row < m.row)
	{
		col = 0;
		while (col < m.col)
		{
			put_images(game, game->img, col, row);
			col++;
		}
		row++;
	}
	mlx_string_put(game->mlx, game->window, CNT_X, CNT_Y, WHITE, "0");
}
