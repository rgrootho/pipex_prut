#include "pipex.h"

void	child_process(t_child child_variables1,t_child child_variables2 , int *pipe_fd, int fd1, int fd2)
{
	check_pipe_fork(close(pipe_fd[fd2]), -1, child_variables1, child_variables2);
	check_pipe_fork(dup2(pipe_fd[fd1], fd1), -1, child_variables1, child_variables2);// die arguments nog veranderen met die struct erin nu naar huis
	check_pipe_fork(dup2(child_variables1.fd_file, fd2), -1, child_variables1, child_variables2);
	execve(child_variables1.path_for_cmd, child_variables1.cmd_and_flags,child_variables1.envp);
	perror("Error!");
	exit(EXIT_FAILURE);
	return; //error message
}

//============================================================================================================

t_child put_stuff_in_struct(t_child child_variables1, t_child child_variables2, char *cmd_flag, char *file, char **envp)
{
	child_variables1.cmd_and_flags = ft_split(cmd_flag, ' ');
	check_split(child_variables1.cmd_and_flags, NULL, child_variables1, child_variables2);
	child_variables1.path_for_cmd = find_correct_path(child_variables1.path_var, child_variables1.cmd_and_flags[0]);
	check_split(NULL, child_variables1.path_for_cmd, child_variables1, child_variables2);
	child_variables1.fd_file = open(file, O_RDWR | O_CREAT );
	check_pipe_fork(child_variables1.fd_file, -1, child_variables1, child_variables2);
	child_variables1.envp = envp;
	return(child_variables1);
}

//============================================================================================================

int main(int argc, char *argv[], char *envp[])
{
	t_child child1_variables;
	t_child child2_variables;
	pid_t	fork_id;
	int pipe_fd[2];

	check_argc(argc);
	child1_variables.path_var = find_string(envp, "PATH", 4);
	check_path_var(child1_variables.path_var);
	child2_variables.path_var = child1_variables.path_var;
	child1_variables = put_stuff_in_struct(child1_variables,child2_variables, argv[2], argv[1], envp);
	child2_variables = put_stuff_in_struct(child2_variables, child1_variables, argv[3], argv[4], envp);
	

	// hier splitten
	// fork id en pipe_fd junnen hier worden initialized

	check_pipe_fork(pipe(pipe_fd), -1, child1_variables, child2_variables);
	fork_id = fork();
	check_pipe_fork(0, fork_id, child1_variables, child2_variables);
	if (fork_id == 0)
		child_process(child1_variables, child2_variables, pipe_fd, 1, 0);
	wait(NULL);
	if (fork() == 0)
		child_process(child2_variables, child1_variables, pipe_fd, 0, 1);
	check_pipe_fork(close(pipe_fd[0]), -1, child1_variables, child2_variables);
	check_pipe_fork(close(pipe_fd[1]), -1, child1_variables, child2_variables);
	check_pipe_fork(close(child1_variables.fd_file), -1, child1_variables, child2_variables);
	check_pipe_fork(close(child2_variables.fd_file), -1, child1_variables, child2_variables);
	free_all(child1_variables, child2_variables);
	return(0);
}