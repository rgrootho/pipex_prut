#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

int	ft_strlen(char *string, char character)
{
	int	i;

	i = 0;
	while (string[i] != character && string[i] != '\0')
		i++;
	return (i);
}

char *find_path_cmd(char *cmd, char *path_var)
{
	int len_path;
	int len_cmd;
	int save_index;
	char *path;

	len_path = 0;
	save_index = 0;
	len_cmd = ft_strlen(cmd, ' ');
	while(path_var[save_index]) // doe anders gewoon split gozer
	{
		len_path = ft_strlen(path_var + save_index, ':');
		path = (char *) malloc ((len_path + len_cmd + 2) * sizeof (char));
		if (!path)
			return(NULL); // error message
		ft_memmove(path_var + save_index, path, len_path);
		path[len_path] = '/';
		ft_memmove(cmd, path + len_path + 1, len_cmd);
		if (access(path, F_OK) == 0)
			return(path); // juiste path gevonden
		if (path_var[save_index + len_path] != '\0')
			save_index = save_index + len_path + 1;
		else
			save_index = save_index + len_path;
		free(path);
	}
	return(NULL); // command bestaat niet, error message
}
char *find_path_in_env(char *envp[], char *path) // noem m anders find string, met misschien lengte als argument erbij
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

	char *path_cmd;
	char *path_var;
	char **cmd_and_flags;
	// if ((access(argv[1], F_OK)) == -1) // denk hier later aan oke
	// 	perror("given file does not exist\n");
	//check of cmd 1 bestaat

	//open file
	path_var = find_path_in_env(envp, "PATH");
	if (path_var == NULL)
		perror("PATH envorinmental variable not found");
	path_cmd = find_path_cmd(argv[2], path_var + 5);
	printf("%s\n", path_cmd);


	//execve: wat heb je nodig?
	//pathname: path van het de command baby !check
	//argv: argumenten, dus de command met flags baby split ugh
	//envp: dat komt later wel baby !checkkkk

	
	return(0);
}
