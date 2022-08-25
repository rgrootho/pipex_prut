#include "pipex.h"

char *find_string(char *envp[], char *string, int len_string)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(envp[j])
	{
		while(envp[j][i] && i < len_string - 1)
		{
			if (envp[j][i] != string[i])
				break;
			i++;
		}
		if (i == 3)
			return(envp[j]);
		j++;
		i = 0;
	}
	return(NULL);
}