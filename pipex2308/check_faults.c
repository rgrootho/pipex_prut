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

int	free_all(t_child var1, t_child var2)
{
	if (var1.path_var)
		free(var1.path_var);
	if (var1.path_for_cmd)
		free(var1.path_for_cmd);
	if (var1.cmd_and_flags)
		free_dbl_pointer(var1.cmd_and_flags);
	if (var2.path_var)
		free(var2.path_var);
	if (var2.path_for_cmd)
		free(var2.path_for_cmd);
	if (var2.cmd_and_flags)
		free_dbl_pointer(var2.cmd_and_flags);
}

int check_argc(int argc)
{
	if (argc != 5)
	{
		if (argc < 5)
			write(2, "Error!: Too few arguments\n", 25 );
		else
			write(2, "Error!: Too many arguments\n", 26);
		exit(EXIT_FAILURE); // weet niet of dit klopt
	}
	return(0);
}

int check_path_var(char *path)
{
	if (path == NULL)
	{
		write(2, "Error!: PATH not in enviornment", 30);
		exit(EXIT_FAILURE);
	}
	return(0);
}

int check_split(char **split, char *string, t_child var1, t_child var2)
{
	if (split == NULL && string == NULL)
	{
		perror("Error!");
		free_all(var1, var2);
		exit(EXIT_FAILURE);
	}
	return(0);
}

int check_pipe_fork(int fd, pid_t fork_id)
{
	if (fd == -1 && fork == -1)
	perror("Error!");
	exit(EXIT_FAILURE);
	return(0);
}