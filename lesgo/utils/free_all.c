/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_all.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rgrootho <rgrootho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 23:34:52 by rgrootho      #+#    #+#                 */
/*   Updated: 2022/10/30 14:24:17 by rgrootho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/pipex.h"

void	free_all(t_childvars vars)
{
	if (vars.cmd_flg)
		free_dbl_pointer(vars.cmd_flg, 0);
	if (vars.path_for_exec)
		free(vars.path_for_exec);
}

int	close_one(int fd)
{
	if (fd > -1)
	{
		close(fd);
		fd = -1;
	}
	return (fd);
}

t_childvars	close_all(t_childvars vars)
{
	if (vars.fd_pipe[0])
		vars.fd_pipe[0] = close_one(vars.fd_pipe[0]);
	if (vars.fd_pipe[1])
		vars.fd_pipe[1] = close_one(vars.fd_pipe[1]);
	if (vars.fd_infile)
		vars.fd_infile = close_one(vars.fd_infile);
	if (vars.fd_outfile)
		vars.fd_outfile = close_one(vars.fd_outfile);
	return (vars);
}
