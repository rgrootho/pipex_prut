/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rgrootho <rgrootho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 23:11:37 by rgrootho      #+#    #+#                 */
/*   Updated: 2022/10/30 22:13:01 by rgrootho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>

typedef struct s_childvars
{
	char	*path_in_env;
	int		fd_pipe[2];
	char	**cmd_flg;
	char	*path_for_exec;
	int		fd_infile;
	int		fd_outfile;
}	t_childvars;

void		check_argc(int argc);
char		*find_string(char *envp[], char *string, int len_string);
t_childvars	pipe_func(t_childvars vars);
void		error_perror(char *string, t_childvars vars);
int			fork_func(char *argv[], char *envp[], t_childvars vars);
void		child_func1(char *argv[], char *envp[], t_childvars vars);
void		child_func2(char *argv[], char *envp[], t_childvars vars);
char		**ft_split(char *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		error_write(char *erstr, int lerr, char *filcmd, t_childvars vars);
t_childvars	find_cmd(t_childvars vars);
char		*ft_strjoin(char *last_part, char *first_part);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *str);
int			free_dbl_pointer(char **array, int len);
void		free_all(t_childvars vars);
void		close_all(t_childvars vars);
void		ft_putstr_fd(char *s, int fd);
int			check_file(char *file, t_childvars vars, int child_num);
int			size_pntr_array(char **pntr_array);
void		error_half(char *string, t_childvars vars, int num);

#endif