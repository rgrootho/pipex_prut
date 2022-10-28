/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rgrootho <rgrootho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 23:26:16 by rgrootho      #+#    #+#                 */
/*   Updated: 2022/10/28 23:26:28 by rgrootho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/pipex.h"

void	check_argc(int argc)
{
	if (argc != 5)
	{
		if (argc < 5)
			write(2, "Error: Not enough arguments\n", 28);
		else
			write(2, "Error: Too many arguments\n", 26);
		exit(1);
	}
}

int	check_file(char *file, t_childvars vars, int child_num)
{
	int	fd;

	fd = 0;
	if (child_num == 1)
	{
		if (access(file, F_OK) == -1)
			error_write(": No such file or directory\n", 29, file, vars);
		else
			fd = open(file, O_RDONLY);
	}
	else
		fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd == -1)
		error_perror(file, vars);
	return (fd);
}
