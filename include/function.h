#ifndef FUNCTION_H
# define FUNCTION_H

# include "minishell.h"

void	sig_handler_c(int signo);
void	minishell(void);
void	error_msg(char *str);
void	print_ascii_art(void);
int	check_exit(char *line);
void	move_cursor(int *row, int *col);
void	run_execve_cmd(t_all *a);

int	ft_strncmp(char *dst, char *src, int size);
int	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *str1, char *str2);

#endif
