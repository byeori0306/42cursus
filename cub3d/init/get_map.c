/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:21:44 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/14 14:52:03 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_map(t_game *game, t_map_info *map_info, char *file_name)
{
	int		fd;
	int		res;
	int		idx;
	char	*line;

	init_map(game, map_info);
	fd = open(file_name, O_RDONLY);
	while (1)
	{
		res = get_next_line(fd, &line);
		if (res < 0)
			break ;
		map_info->start_line -= 1;
		if (map_info->start_line <= 0)
		{
			idx = map_info->start_line * -1 + 1;
			ft_memcpy(map_info->map[idx] + 1, line, ft_strlen(line));
		}
		free(line);
		if (res == 0)
			break ;
	}
	if (res < 0)
		print_err_2(game, "get next line failed");
}

void	modify_map(t_game *game, t_map_info *map_info)
{
	int	i;
	char **temp_map;

	temp_map = malloc(sizeof(char *) * (map_info->row + 1));
	if (!map_info->map)
		print_err_2(game, strerror(ENOMEM));
	i = 0;
	while (i < map_info->row)
	{
		temp_map[i] = malloc(sizeof(char) * (map_info->col + 1));
		if (!map_info->map[i])
			print_err_2(game, strerror(ENOMEM));
		ft_memcpy(temp_map[i], &(map_info->map[i + 1][1]), map_info->col);
		temp_map[i][map_info->col] = '\0';
		i++;
	}
	temp_map[map_info->row] = NULL;
	free_2d(map_info->map);
	map_info->map = temp_map;
}
