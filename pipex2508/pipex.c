#include "pipex.h"

t_child fill_struct(t_child vars, char *cmd_flag, char *file, char**envp, t_child var2)
{
	vars.cmd_and_flags = ft_split(cmd_flag, ' ');
}

int main(int argc, char *argv[], char *envp[])
{
	t_child var_chld1;
	t_child var_chld2;
	
	check_argc(argc, 5);
	var_chld1.path_var = find_string(envp, "PATH", 4);
	check_path_var(var_chld1.path_var);
	var_chld2.path_var = var_chld1.path_var;
	var_chld1 = fill_struct(var_chld1, argv[2], argv[1], envp, var_chld2);
	var_chld2 = fill_struct();

}