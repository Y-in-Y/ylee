#include "minishell.h"

extern t_env	*g_env_list;

void	builtin_echo(t_all *a)
{
	int		i;
	int		n_op;

	if (!a)
		return ;
	n_op = 0;
	if (ft_strncmp(a->arg[1], "-n", 3) == 1)
		n_op = 1;
	i = 1;
	if (n_op == 1)
		i = 2;
	while (a->arg[i])
	{
		printf("%s", a->arg[i]);
		i++;
	}
	if (n_op == 0)
		printf("\n");
}
