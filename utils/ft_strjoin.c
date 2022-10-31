/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rgrootho <rgrootho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 14:41:06 by rgrootho      #+#    #+#                 */
/*   Updated: 2022/10/30 14:41:12 by rgrootho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/pipex.h"

char	*ft_memmove(char *src, char *dest, int len)
{
	size_t	i;

	i = 0;
	while (len > 0 && src[i])
	{
		dest[i] = src[i];
		len--;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *last_part, char *first_part)
{
	char	*new_rs;
	int		len_first_part;
	int		len_last_part;
	int		len_rs;

	len_first_part = ft_strlen(first_part);
	len_last_part = ft_strlen (last_part);
	len_rs = len_first_part + len_last_part;
	new_rs = (char *)malloc((len_rs + 1) * sizeof(char));
	if (new_rs)
	{
		new_rs[len_rs] = '\0';
		ft_memmove(first_part, new_rs, len_first_part);
		ft_memmove(last_part, new_rs + len_first_part, len_last_part);
	}
	free(first_part);
	return (new_rs);
}
