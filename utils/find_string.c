/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_string.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rgrootho <rgrootho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 23:34:01 by rgrootho      #+#    #+#                 */
/*   Updated: 2022/10/31 19:47:04 by rgrootho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/pipex.h"

char	*find_string(char *envp[], char *string, int len_string)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp && envp[j])
	{
		while (envp[j][i] && i < len_string - 1)
		{
			if (envp[j][i] != string[i])
				break ;
			i++;
		}
		if (i == 3)
			return (envp[j] + 5);
		j++;
		i = 0;
	}
	return (NULL);
}
