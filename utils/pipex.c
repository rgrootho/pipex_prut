/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rgrootho <rgrootho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:42:25 by rgrootho      #+#    #+#                 */
/*   Updated: 2022/10/31 22:13:12 by rgrootho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/pipex.h"

void	child_func2(char *argv[], char *envp[], t_childvars vars)
{
	vars.fd_outfile = check_file(argv[4], vars, 2);
	vars.cmd_flg = ft_split(argv[3], ' ');
	if (!vars.path_in_env)
		error_write(": No such file or directory\n", 29, vars.cmd_flg[0], vars);
	vars = find_cmd(vars);
	close(vars.fd_pipe[1]);
	if (dup2(vars.fd_pipe[0], 0) == -1)
		error_perror("dup2", vars);
	if (dup2(vars.fd_outfile, 1) == -1)
		error_perror("dup2", vars);
	execve(vars.path_for_exec, vars.cmd_flg, envp);
	error_perror("execve", vars);
}

void	child_func1(char *argv[], char *envp[], t_childvars vars)
{
	vars.fd_infile = check_file(argv[1], vars, 1);
	vars.cmd_flg = ft_split(argv[2], ' ');
	if (!vars.path_in_env)
		error_write(": No such file or directory\n", 29, vars.cmd_flg[0], vars);
	vars = find_cmd(vars);
	close(vars.fd_pipe[0]);
	if (dup2(vars.fd_pipe[1], 1) == -1)
		error_perror("dup2", vars);
	if (dup2(vars.fd_infile, 0) == -1)
		error_perror("dup2", vars);
	execve(vars.path_for_exec, vars.cmd_flg, envp);
	error_perror("execve", vars);
}

t_childvars	pipe_func(t_childvars vars)
{
	int	pipe_return;

	pipe_return = pipe(vars.fd_pipe);
	if (pipe_return == -1)
	{	
		write(2, "Error: ", 7);
		perror("pipe");
		exit(1);
	}
	return (vars);
}

int	fork_func(char *argv[], char *envp[], t_childvars vars)
{
	pid_t	child_id1;
	pid_t	child_id2;
	int		status;

	child_id1 = fork();
	if (child_id1 < 0)
		error_half("fork", vars);
	if (child_id1 == 0)
		child_func1(argv, envp, vars);
	child_id2 = fork();
	if (child_id2 < 0)
		error_half("fork", vars);
	if (child_id2 == 0)
		child_func2(argv, envp, vars);
	close(vars.fd_pipe[0]);
	close(vars.fd_pipe[1]);
	waitpid(child_id1, &status, 0);
	waitpid(child_id2, &status, 0);
	return (WEXITSTATUS(status));
}
