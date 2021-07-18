#include "minishell.h"

extern t_env	*g_env_list;

void	builtin_cd(t_all *a)
{
	char	*pwd;

	if (!a)
		return ;
	printf("this cmd is cd\n");
	pwd = getcwd(NULL, 0);
	run_export("OLDPWD", pwd);
	if (!a->arg[1])
	{
		chdir("/Users/ylee");
		run_export("PWD", "/Users/ylee");
	}
	else
	{
		chdir(a->arg[1]);
		run_export("PWD", a->arg[1]);
	}
}
