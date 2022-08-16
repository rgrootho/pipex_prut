#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

char *path_splitter(char *path_var, char *cmd);
char	**ft_split(char *s, char c);

char *find_paths_in_env(char *envp[], char *string)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(envp[j])
	{
		while(envp[j][i] && i < 3)
		{
			if (envp[j][i] != string[i])
				break;
			i++;
		}
		if (i == 3)
			return(envp[j]);
		j++;
		i = 0;
	}
	return(NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	int pipe_fd[2];
	pid_t child_id;
	char *path_first_cmd;
	int fd_infile;
	char *path_second_cmd;
	int fd_outfile;
	char *path_var;
	int status;
	char **cmds_and_flags1;
	char **cmds_and_flags2;

	path_var = find_paths_in_env(envp, "PATH");
	cmds_and_flags1 = ft_split(argv[2], ' ');
	cmds_and_flags2 = ft_split(argv[3], ' ');
	path_first_cmd = path_splitter(path_var, cmds_and_flags1[0]);
	path_second_cmd = path_splitter(path_var, cmds_and_flags2[0]);
	fd_infile = open(argv[1], O_RDWR);
	fd_outfile = open(argv[4], O_RDWR);

	printf("%s\n", path_second_cmd);

	pipe(pipe_fd);
	child_id = fork();
	if (child_id == 0)
	{
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		dup2(fd_infile, 0);
		execve(path_first_cmd, cmds_and_flags1, envp);
	}
	child_id = fork();
	if (child_id == 0)
	{
		dup2(pipe_fd[0], 0);
		close(pipe_fd[1]);
		dup2(fd_outfile, 1);
		execve(path_second_cmd, cmds_and_flags2, envp);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(fd_infile);
	close(fd_outfile);
		
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	return(0);
}

// gcc pipex.c find_path_cmd.c ft_strlen.c ft_split.c
// ./a.out infile.txt "grep uwu" "wc -w" outfile.txt