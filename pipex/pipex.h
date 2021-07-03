/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:54:11 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/03 21:11:02 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
// # include <types.h>
# include <wait.h>

# define EXIT_OK 0
# define EXIT_FAIL 1
# define STD_IN 0
# define STD_OUT 1
# define STD_ERR 2
# define CHILD 0

typedef	struct s_pipex
{
	char *in_file;
	char *cmd_1;
	char *cmd_2;
	char *out_file;
	char **paths;
	int pipe_fd[2];
}				t_pipex;

void	print_error(char *message);
void	print_err(char *message, t_pipex *pipex);
void	free_arr(char **arr);
char	**find_paths(char **env);
void	execute_cmd1(t_pipex *pipex);
void	execute_cmd2(t_pipex *pipex);

#endif
