/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   size_pntr_array.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rgrootho <rgrootho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:49:13 by rgrootho      #+#    #+#                 */
/*   Updated: 2022/10/30 14:50:07 by rgrootho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/pipex.h"

int	size_pntr_array(char **pntr_array)
{
	int	i;

	i = 0;
	if (!pntr_array)
		return (0);
	while (pntr_array[i] != NULL)
		i++;
	return (i);
}
