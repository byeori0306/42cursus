/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:32:52 by dahpark           #+#    #+#             */
/*   Updated: 2021/12/11 15:37:57 by dahpark          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_file_type(char *file_name, char *extension)
{
	char	*dot;

	dot = ft_strrchr(file_name, '.');
	if (!dot)
		return (-1);
	return (ft_strncmp(dot, extension, ft_strlen(extension) + 1));
}

void	check_arg(int argc, char **argv)
{
	if (argc < 2)
		print_err("Invalid argument : program requires map(.cub) file");
	else if (argc > 2)
		print_err("Invalid argument : too many arguments");
	if (check_file_type(argv[1], ".cub"))
		print_err("Invalid argumnet : invalid file type");
}
