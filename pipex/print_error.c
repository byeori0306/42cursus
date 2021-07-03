#include "pipex.h"

void	print_error(char *message)
{
	ft_putstr_fd("Error\n", STD_ERR);
	ft_putstr_fd(message, STD_ERR);
	exit(EXIT_FAIL);
}

void	print_err(char *message, t_pipex *pipex)
{
	ft_putstr_fd("Error\n", STD_ERR);
	ft_putstr_fd(message, STD_ERR);
	free_arr(&(pipex->paths));
	exit(EXIT_FAIL);
}