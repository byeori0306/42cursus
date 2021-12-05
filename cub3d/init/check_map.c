/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:14:28 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/03 14:54:29 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_wall_pos(t_map_info *map_info, int x, int y)
{
	int	i;
	int	dx[8] = { 1, -1, 0, 0, -1, 1, -1, 1 }; // 동서남북 북동 북서 남동 남서
	int	dy[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };

	i = 0;
	while (i < 8)
	{
		if (map_info->map[dy[i] + y][dx[i] + x] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	check_map(t_map_info *map_info)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < map_info->row + 1)
	{
		x = 1;
		while (x < map_info->col + 1)
		{
			if (map_info->map[y][x] == ' ')
			{
				x++;
				continue ;
			}
			if (is_wall_pos(map_info, x, y) && map_info->map[y][x] != '1')
				print_err("Invalid map : map must be surrounded by walls");
			x++;
		}
		y++;
	}
	modify_map(map_info);
}
