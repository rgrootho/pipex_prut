#include "pipex.h" 

char *ft_strlcpy(char *dst, char *src, int len)
{
	int i;

	i = 0;
	while (len > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		len --;
	}
	dst[i] = '\0';
	return (dst);
}

