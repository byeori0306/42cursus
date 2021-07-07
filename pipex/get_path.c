/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 19:22:57 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/05 18:09:10 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	add_slash(char **path)
{
	int		i;
	char	*temp;

	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		free(path[i]);
		path[i] = temp;
		i++;
	}
}

char			**find_paths(t_pipex *pipex)
{
	char	**env;
	char	**path;
	char	**paths;
	int		i;

	env = pipex->envp;
	i = 0;
	paths = NULL;
	while (env[i] != NULL)
	{
		path = ft_split(env[i], '=');
		if (ft_strncmp(path[0], "PATH", 5) == 0)
		{
			paths = ft_split(path[1], ':');
			add_slash(paths);
			free_2d(path);
			break ;
		}
		free_2d(path);
		i++;
	}
	if (paths == NULL)
		exit_err("Finding path failed.\n", pipex);
	return (paths);
}
