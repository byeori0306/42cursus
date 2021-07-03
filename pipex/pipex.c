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

void	print_error(char *message)
{
	ft_putstr_fd("Error\n", STD_ERR);
	ft_putstr_fd(message, STD_ERR);
	exit(EXIT_FAIL);
}

void	check_input(int argc, char **argv)
{
	if (argc < 5)
		print_error("It should be executed like ./pipex infile cmd1 cmd2 outfile.\n");
	else if (argc > 5)
		print_error("Too many arguments.\n");
	if (access(argv[1], F_OK) != 0) // F_OK? R_OK?
		print_error("Please check input file.\n");
}

int	main(int argc, char **argv, char **env)
{
	check_input(argc, argv);
}
