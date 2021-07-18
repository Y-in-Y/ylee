#include "minishell.h"

extern t_env	*g_env_list;

void	only_pipe(t_all *a, int i, int **fd)
{
	if (!a || i < 0 || !fd)
		exit(0);
	if (i > 0)
		pipefd_to_stdin(fd[i - 1]);
	if (i < a->pipe_cnt)
		pipefd_to_stdout(fd[i]);
}

void	redir_in(t_all *a, int i, int **fd, t_list *tmp)
{
	if (!a || i < 0 || !fd || !tmp)
		exit(0);
	filefd_to_stdin(tmp->file);
}

void	redir_out(t_all *a, int i, int **fd, t_list *tmp)
{
	if (!a || i < 0 || !fd || !tmp)
		exit(0);
	filefd_to_stdout(tmp->file);
}

void	heredoc(t_all *a, int i, int **fd, t_list *tmp)
{
	if (!a || i < 0 || !fd || !tmp)
		exit(0);
	printf("heredoc func\n");
	exit(0);
}

void	out_append(t_all *a, int i, int **fd, t_list *tmp)
{
	if (!a || i < 0 || !fd || !tmp)
		exit(0);
	final_result_append_to_outfile(tmp->file); //need to rename
}

void	child_process(t_all *a, int i, int **fd)
{
	t_all	*thispage;
	t_list	*tmp;
	int		j;

	j = 0;
	thispage = a;
	while (j < i)
	{
		thispage = thispage->next;
		j++;
	}
	tmp = thispage->redir_list;
	only_pipe(a, i, fd);
	while (tmp)
	{
		if (tmp->redir_flag == 0)
			break ;
		if (tmp->redir_flag == 1)
			redir_in(a, i, fd, tmp);
		else if (tmp->redir_flag == 2)
			redir_out(a, i, fd, tmp);
		else if (tmp->redir_flag == 3)
			heredoc(a, i, fd, tmp);
		else if (tmp->redir_flag == 4)
			out_append(a, i, fd, tmp);
		else
			error_msg("redir error");
		tmp = tmp->next;
	}
	thispage->pipe_cnt = 0;
	run_cmd(thispage);
}
