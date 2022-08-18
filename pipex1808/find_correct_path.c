
#include "pipex.h"

char *find_correct_path(char *path_var, char *cmd)
{
	int i;
	int save_spot;
	char *path;
	int len_cmd;

	len_cmd = ft_strlen(cmd);
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
			if (access(path, F_OK) == 0) // acces voor permission ook :) heel slim lou
				return(path);
			free(path);
			if (path_var[i + 1] != '\0')
				save_spot = i + 1;
		}
		i++;
	}
	return(NULL);
}