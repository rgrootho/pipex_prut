#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

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

char *path_splitter(char *path_var, char *cmd, int len_cmd)
{
	int i;
	int save_spot;
	char *path;

	i = 0;
	save_spot = 0;
	while(path_var[i])
	{
		if (path_var[i] == ':' || path_var[i + 1] == '\0')
		{
			path = (char*) malloc ((i - save_spot + 2 + len_cmd) * sizeof(char));
			if (!path)
				return(NULL);
			ft_strlcpy(path, path_var + save_spot, i - save_spot);
			path[i - save_spot] = '/';
			ft_strlcpy(path + i - save_spot + 1, cmd, len_cmd);
			if (access(path, F_OK) == 0)
				return(path);
			free(path);
			if (path_var[i + 1] != '\0')
				save_spot = i + 1;
		}
		i++;
	}
	return(NULL);
}

int main(void)
{
	char path_var[] = "PATH=/Library/Frameworks/Python.framework/Versions/3.8/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin:/Library/Frameworks/Python.framework/Versions/3.8/bin";
	char *path;
	char cmd[] = "ls";

	path = path_splitter(path_var + 5, cmd, 2);
	printf("%s\n", path);
}