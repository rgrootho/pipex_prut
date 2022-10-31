/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_dbl_pntr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rgrootho <rgrootho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:34:45 by rgrootho      #+#    #+#                 */
/*   Updated: 2022/10/30 14:50:23 by rgrootho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/pipex.h"

int	free_dbl_pointer(char **array, int len)
{
	int	i;

	i = 0;
	if (len == 0)
	{
		while (array[i] != NULL)
		{
			if (array[i])
				free(array[i]);
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			if (array[i] != NULL)
				free(array[i]);
			i++;
		}
	}
	free (array);
	return (0);
}
