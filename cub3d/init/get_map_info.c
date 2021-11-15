/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:52:11 by dahpark           #+#    #+#             */
/*   Updated: 2021/11/13 20:01:47 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	print_map(t_map_info *map_info)
{
	int	i;

	i = 0;
	while (i < map_info->row)
	{
		printf("%s\n", map_info->map[i]);
		i++;
	}
}

static int	is_map_components(t_game *game, char ch)
{
	if (ch == ' ' || ch == '0' || ch == '1')
		return (1);
	else if (ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
	{
		if (game->player.pos_x > 0 || game->player.pos_y > 0)
			print_err("Invalid map : multiple player's start position");
		game->player.pos_x = game->map_info.col;
		game->player.pos_y = game->map_info.row;
		return (1);
	}
	return (0);
}

void	get_map_info(t_game *game, char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0')
    {
        if (!is_map_components(game, line[i]))
			print_err("Invalid map : invalid map components");
        i++;
    }
    if (i > game->map_info.col)
        game->map_info.col = i;
    game->map_info.row += 1;
}

void	get_map(t_map_info *map_info, char *file_name)
{
	int		fd;
	int		res;
	int		idx;
	char	*line;

	map_info->map = malloc(sizeof(char *) * (map_info->row + 1));
	if (!map_info->map)
		print_err(ERRMEM);
	fd = open(file_name, O_RDONLY);
	while ((res = get_next_line(fd, &line)) >= 0)
	{
		map_info->start_line -= 1;
		if (map_info->start_line <= 0)
		{
			idx = map_info->start_line * -1;
			map_info->map[idx] = malloc(sizeof(char) * (map_info->col + 1));
			if (!map_info->map[idx])
				print_err(ERRMEM);
			ft_memset(map_info->map[idx], ' ', map_info->col);
			map_info->map[idx][map_info->col] = '\0';
			ft_memcpy(map_info->map[idx], line, ft_strlen(line));
		}
		if (res == 0)
			break ;
	}
	map_info->map[map_info->row] = NULL;
	if (res < 0)
		print_err("System error : get next line failed");
	if (!map_info->map)
		print_err("Invalid map : map doesn't exist or map isn't the last");
	print_map(map_info);
}