/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:44:07 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 16:44:10 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_process(int (*fds)[2], int i, int n)
{
	if (i == 0)
		dup2(fds[i][1], 1);
	else if (i == n - 1)
		dup2(fds[i - 1][0], 0);
	else
	{
		dup2(fds[i - 1][0], 0);
		dup2(fds[i][1], 1);
	}
	ft_close(fds, n);
}

static void	ft_filedisc_init(int (*fds)[2], int n)
{
	int	i;

	i = -1;
	while (++i <= n - 1)
		pipe(fds[i]);
}

static void	ft_wait(int n, t_env **env, int	*pid, int (*fds)[2])
{
	int		ret;
	int		i;
	char	*tmp;

	i = -1;
	tmp = 0;
	ft_close(fds, n);
	while (++i < n)
	{
		waitpid(pid[i], &ret, 0);
		if (WIFEXITED(ret) != 0)
		{
			tmp = ft_itoa(WEXITSTATUS(ret));
			set_exit_code(tmp, env);
			free(tmp);
		}
	}
	free(fds);
	free(pid);
}

void	ft_fork_norm(int i, t_node *node, t_env **envir, int (*f)[2], int *pid)
{
	int	child;
	int	n;

	n = node_len(node);
	child = 0;
	if (pid[i] == -1)
	{
		free_node(node);
		child_error(pid[i], i);
	}
	else if (pid[i] == 0)
	{
		child_process(f, i, n);
		child = command_for_pipe(*node, envir);
		free_node(node);
		exit(child);
	}
}

void	ft_pipe(t_node *node, t_env **envir)
{
	int	(*fds)[2];
	int	i;
	int	n;
	int	*pid;

	i = -1;
	n = node_len(node);
	fds = ft_calloc(sizeof(int *), node->counts.s_pipe + 1);
	pid = malloc(sizeof(int) * n);
	ft_filedisc_init(fds, n);
	while (++i < n)
	{
		ft_redirs(node);
		pid[i] = fork();
		ft_fork_norm(i, node, envir, fds, pid);
		node = node->next;
	}
	ft_wait(n, envir, pid, fds);
}
