/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:11:43 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/08 21:15:45 by dahpark          ###   ########seoul.kr  */
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

static void	get_img_info(char **dir, char **parsed_line)
{
	if (get_2d_len(parsed_line) != 2)
		print_err("Invalid information : too many or too few information of element");
	*dir = ft_strdup(parsed_line[1]);
	if (!(*dir))
		print_err("System error : memory allocation failed");
}

void	get_elem_info(t_elem_info *elem_info, char *line)
{
	char	**parsed_line;

	parsed_line = ft_split(line, ' ');
	if (!ft_strncmp(parsed_line[0], "NO", 3))
		get_img_info(&(elem_info->no), parsed_line);
	else if (!ft_strncmp(parsed_line[0], "SO", 3))
		get_img_info(&(elem_info->so), parsed_line);
	else if (!ft_strncmp(parsed_line[0], "WE", 3))
		get_img_info(&(elem_info->we), parsed_line);
	else if (!ft_strncmp(parsed_line[0], "EA", 3))
		get_img_info(&(elem_info->ea), parsed_line);
	else if (!ft_strncmp(parsed_line[0], "F", 2)
		|| !ft_strncmp(parsed_line[0], "C", 2))
		get_color_info(elem_info, parsed_line);
	else
		print_err("Invalid information : invalid type identifier");
	free_2d(parsed_line);
}
