#include "pipex.h" 

char *ft_strlcpy(char *dst, char *src, int len);

static int	free_swp(char **splitted_string, int j)
{
	while (j >= 0)
	{
		free(splitted_string[j]);
		j--;
	}
	free(splitted_string);
	return (0);
}