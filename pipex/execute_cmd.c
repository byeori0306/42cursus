/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:33:50 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/05 18:19:38 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	execute_cmd(char **cmd, t_pipex *pipex)
{
	int		i;
	char	*cmd_path;

	i = 0;
	while (pipex->paths[i])
	{
		cmd_path = ft_strjoin(pipex->paths[i], cmd[0]);
		execve(cmd_path, cmd, pipex->envp);
		free(cmd_path);
		i++;
	}
	return (-1);
}

void		execute_cmd_1(t_pipex *pipex)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		exit_err("Fork failed.\n", pipex);
	else if (pid == CHILD)
	{
		redirect_input(pipex);
		close(pipex->pipe_fd[0]);
		if (dup2(pipex->pipe_fd[1], STD_OUT) < 0)
			exit_err("Connect cmd1 and cmd2 failed.\n", pipex);
		close(pipex->pipe_fd[1]);
		if (execute_cmd(pipex->cmd_1, pipex) < 0)
			exit(EXIT_FAIL);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status) == 0)
			exit_err("When executing cmd1, something went wrong.\n", pipex);
	}
}

void		execute_cmd_2(t_pipex *pipex)
{
	close(pipex->pipe_fd[1]);
	if (dup2(pipex->pipe_fd[0], STD_IN) < 0)
		exit_err("Connect cmd1 and cmd2 failed.\n", pipex);
	close(pipex->pipe_fd[0]);
	redirect_output(pipex);
	if (execute_cmd(pipex->cmd_2, pipex) < 0)
		exit_err("When executing cmd2, something went wrong.\n", pipex);
}
