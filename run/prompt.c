/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:16:22 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/25 17:43:55 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_for_norm(t_env **env)
{
	(void)env;
	exit(127);
}

void	status_wait(int status, int exec_status, t_env **en)
{
	char	*str;

	str = ft_itoa(WEXITSTATUS(status));
	if (WIFEXITED(status) && exec_status == 0)
		set_exit_code(str, en);
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}

int	ft_fork(int pid, t_node node, t_env **envir, char	**ch_env)
{
	int	exec_status;

	exec_status = 0;
	if (pid == 0)
	{
		exec_status = child_proc(node, envir, ch_env);
		if (exec_status < 0)
			exit_for_norm(envir);
	}
	return (exec_status);
}

int	commands(t_node node, t_env **envir)
{
	int		exec_status;
	int		pid;
	int		status;
	char	**ch_env;

	exec_status = 0;
	ch_env = list_to_char(*envir);
	ft_redirs(&node);
	if (node.cmd && node.cmd[0] != NULL && is_builtin(node.cmd[0]))
		exec_status = builtin(node, envir);
	else if (node.inf_stat != -1)
	{
		pid = fork();
		exec_status = ft_fork(pid, node, envir, ch_env);
		wait(&status);
		status_wait(status, exec_status, envir);
		signal(SIGINT, &handler);
		signal(SIGQUIT, SIG_IGN);
	}
	free_arr(ch_env);
	return (exec_status);
}

int	command_for_pipe(t_node node, t_env **envir)
{
	int		exec_status;
	char	**ch_env;

	exec_status = 0;
	ch_env = list_to_char(*envir);
	if (node.cmd && node.cmd[0] != NULL && is_builtin(node.cmd[0]))
		exec_status = builtin(node, envir);
	else if (node.cmd && node.inf_stat != -1)
	{
		exec_status = child_proc(node, envir, ch_env);
		if (exec_status < 0)
			exit_for_norm(envir);
		signal(SIGINT, &handler);
		signal(SIGQUIT, SIG_IGN);
	}
	free_arr(ch_env);
	printf("exec_status is %d\n", exec_status);
	if (exec_status < 0)
		return (127);
	return (exec_status);
}
