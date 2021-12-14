/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:20:55 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/14 14:41:34 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	complete_elem_info(t_elem_info *elem_info)
{
	if (elem_info->no.texture && elem_info->so.texture && elem_info->we.texture
		&& elem_info->ea.texture && elem_info->f >= 0 && elem_info->c >= 0)
		return (1);
	return (0);
}

static int	is_map(t_elem_info *elem_info, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if ((line[i] == '0' || line[i] == '1') && complete_elem_info(elem_info))
		return (1);
	return (0);
}

static void	check_line(t_game *game, char *line, int *flag)
{
	if (*flag == 0)
	{
		game->map_info.start_line += 1;
		*flag = is_map(&(game->elem_info), line);
	}
	if (*flag == 0 && ft_strlen(line))
		get_elem_info(game, &(game->elem_info), line);
	else if (*flag == 1)
	{
		if (!ft_strlen(line))
			print_err_2(game, "Invalid map : map content can't be separated by one or more empty line(s)");
		get_map_info(game, line);
	}
}

void	check_file(t_game *game, char *file_name)
{
	int		fd;
	int		res;
	int		flag;
	char	*line;

	flag = 0;
	fd = open(file_name, O_RDONLY);
	while (1)
	{
		res = get_next_line(fd, &line);
		if (res < 0)
			break ;
		check_line(game, line, &flag);
		free(line);
		if (res == 0)
			break ;
	}
	if (res < 0)
		print_err_2(game, "get next line failed");
	if (game->player.pos_x < 0 && game->player.pos_y < 0)
		print_err_2(game, "Invalid map : map needs player");
}
