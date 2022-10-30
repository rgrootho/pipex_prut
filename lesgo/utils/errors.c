/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rgrootho <rgrootho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 23:27:35 by rgrootho      #+#    #+#                 */
/*   Updated: 2022/10/30 22:13:08 by rgrootho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/pipex.h"

void	error_perror(char *string, t_childvars vars)
{
	write(2, "Error: ", 7);
	perror(string);
	free_all(vars);
	close_all(vars);
	exit(1);
}

void	error_half(char *string, t_childvars vars, int num)
{
	write(2, "Error: ", 7);
	perror(string);
	if (num == 2)
		close(vars.fd_infile);
	close(vars.fd_pipe[0]);
	close(vars.fd_pipe[1]);
	exit(1);
}

void	error_write(char *erstr, int lerr, char *filcmd, t_childvars vars)
{
	write(2, "Error: ", 7);
	ft_putstr_fd(filcmd, 2);
	write(2, erstr, lerr);
	free_all(vars);
	close_all(vars);
	exit(127);
}
