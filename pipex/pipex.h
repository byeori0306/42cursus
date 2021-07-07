/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahpark <dahpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 17:54:11 by dahpark           #+#    #+#             */
/*   Updated: 2021/07/05 18:21:10 by dahpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

# define EXIT_FAIL 1
# define STD_IN 0
# define STD_OUT 1
# define STD_ERR 2
# define CHILD 0

typedef	struct	s_pipex
{
	char	*infile;
	char	**cmd_1;
	char	**cmd_2;
	char	*outfile;
	char	**envp;
	char	**paths;
	int		pipe_fd[2];
}				t_pipex;

void			free_2d(char **arr);
void			exit_err(char *message, t_pipex *pipex);
char			**find_paths(t_pipex *pipex);
void			redirect_input(t_pipex *pipex);
void			redirect_output(t_pipex *pipex);
void			execute_cmd_1(t_pipex *pipex);
void			execute_cmd_2(t_pipex *pipex);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
