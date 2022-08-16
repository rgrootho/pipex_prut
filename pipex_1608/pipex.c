#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

child_process(char *argv, int fd_rd_wr_pipe, int fd_rd_wr_file, int *pipe_fd, char *envp[])
{
	char **cmd_and_flags;
	char *path_var;
	char *path_for_cmd;
	char *fd_for_file;

	cmd_and_flags = ft_split(argv,':');
	path_var = find_string(envp, "PATH");
	path_for_cmd = find_correct_path(path_var, cmd_and_flags);
	fd_for_file = open()

		dup2(pipe_fd[0], 0);
		close(pipe_fd[1]);
		dup2(fd_outfile, 1);
		execve(path_second_cmd, cmds_and_flags2, envp);
}

int main(int argc, char *argv[], char *envp[])
{
	t_list 
	int pipe_fd[2];
	int status;

	if (fork() == 0)
		child_process(argv[2], 1, 0, pipe_fd, envp);
	wait(NULL);
	if (fork == 0)
		child_process(argv[3], 0, 1, pipe_fd, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);

	waitpid(-1, &status, 0);//hier iets beter naar kijken;
	waitpid(-1, &status, 0);
	return(0);
}