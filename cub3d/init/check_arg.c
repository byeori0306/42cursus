/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:32:52 by dahpark           #+#    #+#             */
/*   Updated: 2021/11/16 19:58:25 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_file_type(char *file_name)
{
	char	*dot;

	dot = ft_strrchr(file_name, '.');
	if (!dot)
		return (-1);
	return (ft_strncmp(dot, ".cub", 5));
}

void	check_arg(int argc, char **argv)
{
	if (argc < 2)
		print_err("Invalid argument : program requires map(.cub) file");
	else if (argc > 2)
		print_err("Invalid argument : too many arguments");
	if (check_file_type(argv[1]))
		print_err("Invalid argumnet : invalid file type");
}
