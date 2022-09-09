#include "pipex.h"

int free_dbl_pointer(char **array)
{
	int i;

	i = 0;
	while(array[i] != NULL)
	{
		if(array[i])
			free(array[i]);
		i++;
	}
	free(array);
	return(0);
}

int	free_all(t_child var_chld)
{
	if (var_chld.path_for_cmd1)
		free(var_chld.path_for_cmd1);
	if (var_chld.path_for_cmd2)
		free(var_chld.path_for_cmd2);
	if (var_chld.cmd_and_flags1)
		free_dbl_pointer(var_chld.cmd_and_flags1);
	if (var_chld.cmd_and_flags2)
		free_dbl_pointer(var_chld.cmd_and_flags2);
	return(0);
}