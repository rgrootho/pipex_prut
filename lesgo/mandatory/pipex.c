/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rgrootho <rgrootho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 23:02:10 by rgrootho      #+#    #+#                 */
/*   Updated: 2022/10/29 01:22:39 by rgrootho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_childvars	vars;
	int			exit_stat;

	check_argc(argc);
	vars.path_in_env = find_string(envp, "PATH", 4);
	vars = pipe_func(vars);
	exit_stat = fork_func(argv, envp, vars);
	vars = close_all(vars);
	free_all(vars);
	return (exit_stat);
}
