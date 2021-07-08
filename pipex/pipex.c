/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:54:24 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/05 18:20:44 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	check_input(int argc, t_pipex *pipex)
{
	int out;

	if (argc < 5)
		exit_err("form : ./pipex infile \"cmd1\" \"cmd2\" outfile\n", pipex);
	else if (argc > 5)
		exit_err("Too many arguments.\n", pipex);
	if (access(pipex->infile, F_OK) != 0)
		exit_err("Please check input file.\n", pipex);
	else if (access(pipex->infile, R_OK) != 0)
		exit_err("Permission to input file denied.\n", pipex);
	if (access(pipex->outfile, F_OK) == 0 && access(pipex->outfile, W_OK) != 0)
		exit_err("Permission to output file denied.\n", pipex);
	else if (access(pipex->outfile, F_OK) != 0)
	{
		out = open(pipex->outfile, O_CREAT, 0644);
		close(out);
	}
}

static	void	init_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	pipex->infile = argv[1];
	pipex->cmd_1 = NULL;
	pipex->cmd_2 = NULL;
	pipex->outfile = argv[argc - 1];
	pipex->envp = env;
	pipex->paths = NULL;
}

static	void	fill_pipex(t_pipex *pipex, char **argv)
{
	if (ft_strlen(argv[2]) == 0 || ft_strlen(argv[3]) == 0)
		exit_err("Wrong command.\n", pipex);
	pipex->cmd_1 = ft_split(argv[2], ' ');
	pipex->cmd_2 = ft_split(argv[3], ' ');
	if (!pipex->cmd_1 || !pipex->cmd_2)
		exit_err("Parse command failed.\n", pipex);
	pipex->paths = find_paths(pipex);
	if (pipe(pipex->pipe_fd) < 0)
		exit_err("Create pipe failed.\n", pipex);
}

static	int	wifexited(int status)
{
	int result;

	result = (status) & 0x7f;
	return (result == 0);
}

int				main(int argc, char **argv, char **env)
{
	t_pipex pipex;
	int status;

	init_pipex(&pipex, argc, argv, env);
	check_input(argc, &pipex);
	fill_pipex(&pipex, argv);
	execute_cmd_1(&pipex);
	execute_cmd_2(&pipex);
	wait(&status);
	if (wifexited(status) == 0)
		exit_err("When executing cmd, something went wrong.\n", &pipex);
	exit(0);
}
