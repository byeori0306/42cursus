/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 03:32:46 by dahpark           #+#    #+#             */
/*   Updated: 2021/06/24 10:39:58 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	img->wall = get_image(game, "./img/wall.png");
	img->floor = get_image(game, "./img/floor.png");
	img->closed = get_image(game, "./img/closed.png");
	img->opened = get_image(game, "./img/opened.png");
	img->cherry = get_image(game, "./img/cherry.png");
	img->player_start = get_image(game, "./img/player_start.png");
	img->player_w = get_image(game, "./img/player_w.png");
	img->player_a = get_image(game, "./img/player_a.png");
	img->player_s = get_image(game, "./img/player_s.png");
	img->player_d = get_image(game, "./img/player_d.png");
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
		put_image(game, img.player_start, x, y);
		init_player(&(game->player), x, y);
	}
	else if (m.map[y][x] == 'E')
		put_image(game, img.closed, x, y);
	else if (m.map[y][x] == 'C')
		put_image(game, img.cherry, x, y);
}

void			put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img,
	TILE_SIZE * x, TILE_SIZE * y);
}

void			draw_map(t_game *game)
{
	t_map_info	m;
	int			x;
	int			y;

	get_images(game, &(game->img));
	m = game->map_info;
	y = 0;
	while (y < m.row)
	{
		x = 0;
		while (x < m.col)
		{
			put_images(game, game->img, x, y);
			x++;
		}
		y++;
	}
}
