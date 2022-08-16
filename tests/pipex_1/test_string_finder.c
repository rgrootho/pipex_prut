#include <unistd.h>
#include <stdio.h>

char *find_path_in_env(char *envp[], char *path)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(envp[i])
	{
		while(envp[i][j] && j < 4)
		{
			if (envp[i][j] == path[j])
			{
				if (j == 3)
					return(&envp[i][0]);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return(NULL);
}

int main(int argc, char *argv[], char *envp[])
{
	char *path_var;

	path_var = find_path_in_env(envp, "PATH");
	if (path_var == NULL)
		perror("PATH not found");
	printf("%s\n", path_var + 5);
	return(0);
}