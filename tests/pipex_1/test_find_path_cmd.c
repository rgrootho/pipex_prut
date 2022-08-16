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
	len_cmd = ft_strlen(cmd, '\0');
	while(path_var[save_index])
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

int main(int argc, char *argv[], char *envp[])
{
	char *string;

	string = find_path_cmd("ls", "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/share/dotnet:/usr/local/munki:~/.dotnet/tools");
	printf("%s\n", string);
	return(0);
}