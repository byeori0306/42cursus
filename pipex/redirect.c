/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:33:34 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/05 17:23:28 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_input(t_pipex *pipex)
{
	int file_fd;

	file_fd = open(pipex->infile, O_RDONLY);
	if (file_fd < 0)
		exit_err("Open infile failed.\n", pipex);
	if (dup2(file_fd, STD_IN) < 0)
		exit_err("Redirect input failed.\n", pipex);
	close(file_fd);
}

void	redirect_output(t_pipex *pipex)
{
	int file_fd;

	file_fd = open(pipex->outfile, O_RDWR | O_TRUNC);
	if (file_fd < 0)
		exit_err("Open outfile failed.\n", pipex);
	if (dup2(file_fd, STD_OUT) < 0)
		exit_err("Redirect output failed.\n", pipex);
	close(file_fd);
}
