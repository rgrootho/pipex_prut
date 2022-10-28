#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	t_child child_var;

	check_argc(argc, 5);
	child_var.path_var = find_string("PATH", 4);
	check_path_var(child_var.path_var);

}