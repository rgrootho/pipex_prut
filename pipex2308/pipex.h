#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>

typedef	struct s_child
{
	char *path_var;
	char *path_for_cmd;
	char **cmd_and_flags;
	char **envp;
	int fd_file;

}	t_child;

char	**ft_split(char *s, char c);
char	*ft_strlcpy(char *dst, char *src, int len);
char	*find_string(char *envp[], char *string, int len_string);
char	*find_correct_path(char *path_var, char *cmd);
size_t	ft_strlen(const char *str);
char	*ft_strlcpy(char *dst, char *src, int len);
int		check_argc(int argc);
int		check_path_var(char *path);
int		check_split(char **split, char *string, t_child var1, t_child var2);
int		check_pipe_fork(int fd, pid_t fork_id, t_child var1, t_child var2);
int		free_all(t_child var1, t_child var2);

#endif