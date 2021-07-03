/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:54:24 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/03 21:11:00 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

static void	check_input(int argc, char **argv)
{
	if (argc < 5)
		print_error("It should be executed like ./pipex infile cmd1 cmd2 outfile.\n");
	else if (argc > 5)
		print_error("Too many arguments.\n");
	if (access(argv[1], F_OK) != 0) // F_OK? R_OK?
		print_error("Please check input file.\n");
}

static void	init_pipex(t_pipex *pipex, char **argv, char **env)
{
	int fds[2];

	if (pipe(fds[2]) < 0)
		print_error("Create pipe failed.\n");
	pipex->in_file = argv[1];
	pipex->cmd_1 = argv[2];
	pipex->cmd_2 = argv[3];
	pipex->out_file = argv[4];
	pipex->paths = find_paths(env);
	pipex->pipe_fd[2] = fds[2];
}

int	main(int argc, char **argv, char **env)
{
	t_pipex pipex;
	check_input(argc, argv);
	init_pipex(&pipex, argv, env);
	execute_cmd1(&pipex);
	execute_cmd2(&pipex);
}
