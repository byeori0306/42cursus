/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:45:21 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/05 18:07:09 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_2d(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	exit_err(char *message, t_pipex *pipex)
{
	ft_putstr_fd("Error\n", STD_ERR);
	ft_putstr_fd(message, STD_ERR);
	if (pipex->cmd_1)
		free_2d(pipex->cmd_1);
	if (pipex->cmd_2)
		free_2d(pipex->cmd_2);
	if (pipex->paths)
		free_2d(pipex->paths);
	exit(EXIT_FAIL);
}
