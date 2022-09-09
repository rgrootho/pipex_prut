#include "pipex.h"

t_child fill_struct(t_child var_chld, char **argv, char **envp)
{
	var_chld.cmd_and_flags1 = ft_split(argv[2], ' ');
	var_chld.cmd_and_flags2 = ft_split(argv[3], ' ');
	check_split(var_chld);
	var_chld.path_for_cmd1 = find_correct_path(var_chld);
	var_chld.path_for_cmd2 = find_correct_path(var_chld);
}

int main(int argc, char *argv[], char *envp[])
{
	t_child var_chld;
	
	check_argc(argc, 5);
	var_chld.path_var = find_string(envp, "PATH", 4);
	check_path_var(var_chld.path_var);
	var_chld = fill_struct(var_chld, argv, envp);
}