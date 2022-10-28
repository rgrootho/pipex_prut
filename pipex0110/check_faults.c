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
	if (var1.path_for_cmd)
		free(var1.path_for_cmd);
	if (var1.cmd_and_flags)
		free_dbl_pointer(var1.cmd_and_flags);
	if (var2.path_for_cmd)
		free(var2.path_for_cmd);
	if (var2.cmd_and_flags)
		free_dbl_pointer(var2.cmd_and_flags);
	return(0);
}

int check_argc(int argc, int expected_argc)
{
	if (argc != expected_argc)
	{
		if (argc < expected_argc)
			write(2, "Error!: Too few arguments\n", 25 );
			//perror ("Error!: Too few arguments\n") niet deze, er staat miks in errno
		else
			write(2, "Error!: Too many arguments\n", 26);
			//perror ("Error!: Too many arguments\n")
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

int check_pipe_fork(int fd, pid_t fork_id, t_child var1, t_child var2)
{
	if (fd == -1 && fork_id == -1)
	{
		perror("Error!");
		free_all(var1, var2);
		exit(EXIT_FAILURE);
	}
	return(0);
}
