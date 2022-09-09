#include "pipex.h"

int		check_split(t_child var_chld)
{
	if (var_chld.cmd_and_flags1 == NULL || var_chld.cmd_and_flags2 == NULL)
	{
		perror("Error!");
		free_all(var_chld);
		exit(EXIT_FAILURE);
	}
	return(0);
}