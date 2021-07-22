#include "minishell.h"

extern t_env	*g_env_list;

void	print_echo(t_all *a, int i, int n_op)
{


}

void	builtin_echo(t_all *a)
{
	int		i;
	int		n_op;

	if (!a)
		return ;
	if (a->redir_list && a->redir_list->redir_flag != 0)
		child_process(a, 0, 0); //need to rename function
	i = 0;
    n_op = a->echo_n_cnt;
	i = n_op + 1;
	
    while (a->arg[i])
	{
		printf("%s", a->arg[i]);
		if (a->arg[i + 1])
			printf(" ");
		i++;
	}
	if (n_op == 0)
		printf("\n");
}
