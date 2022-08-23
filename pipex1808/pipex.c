#include "pipex.h"

void	child_process(t_child child_variables, int *pipe_fd, int fd1, int fd2)
{
	close(pipe_fd[fd2]);
	dup2(pipe_fd[fd1], fd1);
	dup2(child_variables.fd_file, fd2);
	execve(child_variables.path_for_cmd, child_variables.cmd_and_flags,child_variables.envp);
	return; //error message
}

//============================================================================================================

t_child put_stuff_in_struct(t_child child_variables, char *cmd_flag, char *file, char **envp)
{
	child_variables.cmd_and_flags = ft_split(cmd_flag, ' ');
	child_variables.path_for_cmd = find_correct_path(child_variables.path_var, child_variables.cmd_and_flags[0]);
	child_variables.fd_file = open(file, O_RDWR);
	child_variables.envp = envp;
	return(child_variables);
}

//============================================================================================================

int main(int argc, char *argv[], char *envp[])
{
	t_child child1_variables;
	t_child child2_variables;
	int pipe_fd[2];

	child1_variables.path_var = find_string(envp, "PATH", 4); //aanpassen met len erbij voor gebruik in toekomst
	child2_variables.path_var = child1_variables.path_var;
	child1_variables = put_stuff_in_struct(child1_variables, argv[2], argv[1], envp);
	child2_variables = put_stuff_in_struct(child2_variables, argv[3], argv[4], envp);
	pipe(pipe_fd);
	if (fork() == 0)
		child_process(child1_variables, pipe_fd, 1, 0);
	wait(NULL);
	if (fork() == 0)
		child_process(child2_variables, pipe_fd, 0, 1);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(child1_variables.fd_file);
	close(child2_variables.fd_file);
	// free all things
	return(0);
}