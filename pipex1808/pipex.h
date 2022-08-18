#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

typedef	struct s_child
{
	char *path_var;
	char *path_for_cmd;
	char **cmd_and_flags;
	int fd_file;

}	t_child;

char	**ft_split(char *s, char c);
char	*ft_strlcpy(char *dst, char *src, int len);
char	*find_string(char *envp[], char *string);
char	*find_correct_path(char *path_var, char *cmd);




#endif