/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:22:57 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/03 21:11:27 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	add_slash(char **path)
{
	int i;
	char *temp;

	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		free(path[i]);
		path[i] = temp;
		i++;
	}
}

void	free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	**find_paths(char **env)
{
	char **path;
	char **paths;
	int i;

	i = 0;
	paths = NULL;
	while (env[i] != NULL)
	{
		path = ft_split(env[i], '=');
		if (ft_strncmp(path[0], "PATH", 5) == 0)
		{
			paths = ft_split(path[1], ':');
			add_slash(paths);
			free_arr(path);
			break;
		}
		free_arr(path);
		i++;
	}
	if (paths == NULL)
		print_error("Finding path failed.\n");
	return (paths);
}
