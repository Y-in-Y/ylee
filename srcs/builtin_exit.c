#include "minishell.h"

extern t_env	*g_env_list;

void	builtin_exit(t_all *a)
{
	if (!a)
		return ;
	printf("exit\n");
	exit(0);
}
