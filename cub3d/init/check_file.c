/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:20:55 by dahpark           #+#    #+#             */
/*   Updated: 2021/11/16 19:56:27 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	complete_elem_info(t_elem_info *elem_info)
{
	if (elem_info->no && elem_info->so && elem_info->we
		&& elem_info->ea && elem_info->f && elem_info->c)
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
		if (flag == 0)
		{
			game->map_info.start_line += 1;
			flag = is_map(&(game->elem_info), line);
		}
		if (flag == 0 && ft_strlen(line))
			get_elem_info(&(game->elem_info), line);
		else if (flag == 1)
		{
			if (!ft_strlen(line))
				print_err("Invalid map : map content can't be separated by one or more empty line(s)");
			get_map_info(game, line);
		}
		free(line);
		if (res == 0)
			break ;
	}
	if (res < 0)
		print_err("System error : get next line failed");
}
