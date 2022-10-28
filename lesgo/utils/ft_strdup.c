#include "../mandatory/pipex.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*p;

	i = ft_strlen(s1) + 1;
	p = (char *)malloc(i * sizeof(char));
	if (p == 0)
		return (0);
	ft_strlcpy(p, s1, i);
	return (p);
}