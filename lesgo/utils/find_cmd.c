/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_cmd.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rgrootho <rgrootho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 23:29:57 by rgrootho      #+#    #+#                 */
/*   Updated: 2022/10/28 23:31:59 by rgrootho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/pipex.h"

char	**loup(t_childvars *vars, char **path_split, int i)
{
	path_split[i] = ft_strjoin("/", path_split[i]);
	if (path_split[i] == NULL)
		return (path_split);
	path_split[i] = ft_strjoin(vars->cmd_flg[0], path_split[i]);
	if (path_split[i] == NULL)
		return (path_split);
	if (path_split[i] && access(path_split[i], F_OK) == 0)
	{
		vars->path_for_exec = ft_strdup(path_split[i]);
		return (path_split);
	}
	return (path_split);
}

t_childvars	find_cmd(t_childvars vars)
{
	char	**path_split;
	int		i;
	int		size_path_split;

	i = 0;
	if (!vars.cmd_flg)
		return (vars);
	path_split = ft_split(vars.path_in_env, ':');
	size_path_split = size_pntr_array(path_split);
	while (path_split && path_split[i])
	{
		path_split = loup(&vars, path_split, i);
		if (path_split[i] == NULL || vars.path_for_exec)
			break ;
		i++;
	}
	if (!path_split)
		return (vars);
	if (path_split[i] == NULL && i == size_path_split)
		error_write(": command not found\n", 21, vars.cmd_flg[0], vars);
	free_dbl_pointer(path_split, size_path_split);
	return (vars);
}
