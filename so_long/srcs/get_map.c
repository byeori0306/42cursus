/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 03:30:46 by dahpark           #+#    #+#             */
/*   Updated: 2021/06/24 13:36:27 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

static	void	init_map(t_map_info *map_info)
{
	map_info->map = (char **)malloc(sizeof(char *) * map_info->row);
	if (map_info->map == NULL)
		print_error(ERR_MALLOC);
}

void			free_map(t_map_info *map_info, int i)
{
	while (i--)
		free(map_info->map[i]);
	free(map_info->map);
}

void			get_map(char *file, t_map_info *info)
{
	int		fd;
	int		reader;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	init_map(info);
	while ((reader = get_next_line(fd, &line)) >= 0)
	{
		if (!(info->map[i] = (char *)malloc(sizeof(char) * (info->col + 1))))
		{
			free_map(info, i);
			print_error(ERR_MALLOC);
		}
		ft_memcpy(info->map[i], line, info->col + 1);
		i++;
		free(line);
		if (i == info->row)
			break ;
	}
	close(fd);
}
