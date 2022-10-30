/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_all.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rgrootho <rgrootho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 23:34:52 by rgrootho      #+#    #+#                 */
/*   Updated: 2022/10/30 21:08:02 by rgrootho      ########   odam.nl         */
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

void	close_all(t_childvars vars)
{
	close(vars.fd_pipe[0]);
	close(vars.fd_pipe[1]);
	close(vars.fd_infile);
	close(vars.fd_outfile);
}
