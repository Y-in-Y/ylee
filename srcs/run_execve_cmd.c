#include "minishell.h"

void	run_execve_cmd(t_all *a)
{
	if (!a)
		error_msg("error");
	printf("only one non builtin cmd case\n");
}
