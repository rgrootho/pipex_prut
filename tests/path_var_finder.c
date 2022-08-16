#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

char *find_paths_in_env(char *envp[], char *string)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(envp[j])
	{
		while(envp[j][i] && i < 3)
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

int main(int argc, char *argv[], char *envp[])
{
	char *path;
	
	path = find_paths_in_env(envp, "PATH");
	printf("%s\n", path);
	return(0);
}