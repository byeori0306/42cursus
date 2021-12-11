/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:11:43 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/11 16:04:34 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_rgb(char **colors, int **rgb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (colors[i])
	{
		j = 0;
		while (colors[i][j])
		{
			if (!ft_isdigit(colors[i][j]))
				print_err("Invalid information : decimal RGB value required");
			j++;
		}
		i++;
	}
	i = 0;
	while (colors[i])
	{
		(*rgb)[i] = ft_atoi(colors[i]);
		if ((*rgb)[i] < 0 || (*rgb)[i] > 255)
			print_err("Invalid information : RGB value out of range");
		i++;
	}
}

static int	convert_dec_to_hex(int *rgb)
{
	int	result;

	result = rgb[2] + (rgb[1] << 8) + (rgb[0] << 16);
	return (result);
}

static void	get_color_info(t_elem_info *elem_info, char **parsed_line) // 여기서 계산
{
	char	**colors;
	int		*rgb;

	if (get_2d_len(parsed_line) != 2)
		print_err("Invalid information : too many or too few information of element");
	colors = ft_split(parsed_line[1], ',');
	rgb = malloc(sizeof(int) * 3);
	if (get_2d_len(colors) != 3)
		print_err("Invalid information : need RGB colors");
	check_rgb(colors, &rgb);
	if (!ft_strncmp(parsed_line[0], "F", 2))
		elem_info->f = convert_dec_to_hex(rgb);
	else if (!ft_strncmp(parsed_line[0], "C", 2))
		elem_info->c = convert_dec_to_hex(rgb);
	free_2d(colors);
	free(rgb);
}

static void	get_wall_img(t_game *game, int **dir, char **parsed_line)
{
	int		size;
	void	*image;
	int		bpp;
	int		line_size;
	int		endian;
	
	if (get_2d_len(parsed_line) != 2)
		print_err("Invalid information : too many or too few information of element");
	if (check_file_type(parsed_line[1], ".png"))
		print_err("Invalid information : program requires (.png) image file");
	size = TEX_SIZE;
	image = mlx_png_file_to_image(game->mlx, parsed_line[1], &size, &size);
	if (!image)
		print_err("Load image failed\n");
	*dir = (int *)mlx_get_data_addr(image, &bpp, &line_size, &endian);
}

void	get_elem_info(t_game *game, t_elem_info *elem_info, char *line)
{
	char	**parsed_line;
	(void)game;
	parsed_line = ft_split(line, ' ');
	if (!ft_strncmp(parsed_line[0], "NO", 3))
		get_wall_img(game, &(elem_info->no), parsed_line);
	else if (!ft_strncmp(parsed_line[0], "SO", 3))
		get_wall_img(game, &(elem_info->so), parsed_line);
	else if (!ft_strncmp(parsed_line[0], "WE", 3))
		get_wall_img(game, &(elem_info->we), parsed_line);
	else if (!ft_strncmp(parsed_line[0], "EA", 3))
		get_wall_img(game, &(elem_info->ea), parsed_line);
	else if (!ft_strncmp(parsed_line[0], "F", 2)
		|| !ft_strncmp(parsed_line[0], "C", 2))
		get_color_info(elem_info, parsed_line);
	else
		print_err("Invalid information : invalid type identifier");
	free_2d(parsed_line);
}
