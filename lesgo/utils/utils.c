#include "../mandatory/pipex.h"

void    child_func2(char *argv[],char *envp[] ,t_childvars vars)
{
    vars.fd_outfile = check_file(argv[4], vars, 2);
    vars.cmd_flg = ft_split(argv[3], ' '); // mocht er nou iets fout gaan in split, ook naar een error_func
    if (!vars.path_in_env)
        error_write(": No such file or directory\n", 29, vars.cmd_flg[0], vars);
    vars = find_cmd(vars);
    close(vars.fd_pipe[1]);
    dup2(vars.fd_pipe[0], 0);
    dup2(vars.fd_outfile, 1);
    execve(vars.path_for_exec, vars.cmd_flg, envp);
    error_perror("execve ", vars);// of exit(127) ofozo zegt internet
}

void    child_func1(char *argv[],char *envp[] ,t_childvars vars)
{
    vars.fd_infile = check_file(argv[1], vars, 1);
    vars.cmd_flg = ft_split(argv[2], ' '); // mocht er nou iets fout gaan in split, ook naar een error_func
    if (!vars.path_in_env)
        error_write(": No such file or directory\n", 29, vars.cmd_flg[0], vars);
    vars = find_cmd(vars);
    close(vars.fd_pipe[0]);
    dup2(vars.fd_pipe[1],  1);
    dup2(vars.fd_infile, 0);
    execve(vars.path_for_exec, vars.cmd_flg, envp);
    error_perror("execve ", vars);
}

t_childvars pipe_func(t_childvars vars)
{
    int pipe_return;

    pipe_return = pipe(vars.fd_pipe);
    if(pipe_return == -1)
        error_perror("", vars); 
    return(vars);
}

int fork_func(char *argv[],char *envp[] ,t_childvars vars)
{
    pid_t child_id1;
    pid_t child_id2;
    int    status;

    child_id1 = fork();
    if (child_id1 < 0)
        error_perror("", vars);
    if (child_id1 == 0)
        child_func1(argv, envp, vars); 
    child_id2 = fork();
    if (child_id2 < 0)
        error_perror("", vars);
    if (child_id2 == 0)
        child_func2(argv, envp, vars);

    close(vars.fd_pipe[0]);
    close(vars.fd_pipe[1]);
    waitpid(child_id1, &status, 0);
    waitpid(child_id2, &status, 0);
    return(WEXITSTATUS(status));    
}