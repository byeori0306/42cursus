#include "pipex.h"

static void	execute_cmd(char *cmd, char **path)
{
	int i;
	char *cmd_path;
	char **argv;

	i = 0;
	argv = ft_split(cmd, ' ');
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], cmd[0]);
		execve(cmd_path, argv, NULL);
		free(cmd_path);
	}
	free_arr(argv);
	print_error("Please make sure you entered the right command.\n");
}

void	execute_cmd1(t_pipex *pipex)
{
	int file_fd;
	pid_t pid;

	file_fd = open(pipex->in_file, O_RDONLY);
	if (file_fd < 0)
		print_error("Open file failed.\n");
	
	pid = fork();
	if (pid < 0)
		print_error("Fork failed.\n");
	else if (pid == CHILD)
	{
		if (dup2(file_fd, STD_IN) < 0)
			print_error("Redirection failed.\n");
		close(file_fd);
		if (dup2(pipex->pipe_fd[0], STD_OUT) < 0)
			print_error("Connect cmd1 and cmd2 failed.\n");
		execute_cmd(pipex->cmd_1, pipex->paths);
	}
	else
		wait(NULL);
}

void	execute_cmd2(t_pipex *pipex)
{
	int file_fd;

	file_fd = open(pipex->out_file, O_TRUNC | O_CREAT, 0644);
	if (file_fd < 0)
		print_error("Open file failed.\n");
	if (dup2(file_fd, STD_OUT) < 0)
		print_error("Redirection failed.\n");
	close(file_fd);
	if (dup2(pipex->pipe_fd[1], STD_IN) < 0)
		print_error("Connect cmd1 and cmd2 failed.\n");
	execute_cmd(pipex->cmd_2, pipex->paths);
}