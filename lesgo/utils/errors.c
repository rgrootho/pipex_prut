/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rgrootho <rgrootho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 23:27:35 by rgrootho      #+#    #+#                 */
/*   Updated: 2022/10/29 01:22:47 by rgrootho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/pipex.h"

void	error_perror(char *string, t_childvars vars)
{
	write(2, "Error: ", 7);
	ft_putstr_fd(string, 2);
	perror("");
	free_all(vars);
	vars = close_all(vars);
	exit(1);
}

void	error_write(char *erstr, int lerr, char *filcmd, t_childvars vars)
{
	write(2, "Error: ", 7);
	ft_putstr_fd(filcmd, 2);
	write(2, erstr, lerr);
	free_all(vars);
	vars = close_all(vars);
	exit(127);
}
