/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 06:30:10 by dahpark           #+#    #+#             */
/*   Updated: 2021/06/24 13:00:43 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

static	void	check_first_line(char *line, t_map_info *map_info)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			print_error(ERR_WALL);
		i++;
	}
	if (i <= 2)
		print_error(ERR_RECT);
	map_info->col = i;
}

static	void	check_last_line(char *l1, char *l2, t_map_info *map_info)
{
	char	*last_line;
	int		i;

	i = 0;
	if (ft_strlen(l1) > 0)
	{
		last_line = l1;
		map_info->row++;
	}
	else
		last_line = l2;
	while (last_line[i])
	{
		if (last_line[i] != '1')
			print_error(ERR_WALL);
		i++;
	}
	if (i != map_info->col)
		print_error(ERR_RECT);
	free(l1);
	free(l2);
}

static	void	check_lines(char *line, t_map_info *map_info)
{
	int i;

	i = 1;
	if (line[0] != '1')
		print_error(ERR_WALL);
	while (line[i])
	{
		if (line[i] == 'P')
			map_info->start_pos++;
		else if (line[i] == 'E')
			map_info->exit++;
		else if (line[i] == 'C')
			map_info->collectibles++;
		i++;
	}
	if (line[i - 1] != '1')
		print_error(ERR_WALL);
	if (i != map_info->col)
		print_error(ERR_RECT);
}

static	void	check_components(t_map_info *map_info)
{
	if (map_info->start_pos < 1 || map_info->start_pos > 1)
		print_error(ERR_CHAR);
	if (map_info->exit < 1)
		print_error(ERR_CHAR);
	if (map_info->collectibles < 1)
		print_error(ERR_CHAR);
}

void			check_map(char *file, t_map_info *map_info)
{
	int		res;
	int		fd;
	char	*line;
	char	*last_line;

	fd = open(file, O_RDONLY);
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (res == -1)
			print_error("File reading failed.\n");
		if (map_info->row == 0)
		{
			check_first_line(line, map_info);
			last_line = (char *)malloc(sizeof(char) * (map_info->col + 1));
		}
		else
			check_lines(line, map_info);
		map_info->row++;
		ft_memcpy(last_line, line, map_info->col + 1);
		free(line);
	}
	check_components(map_info);
	check_last_line(line, last_line, map_info);
	close(fd);
}
