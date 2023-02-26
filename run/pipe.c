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

void	ft_close(int (*fd)[2], int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}

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
	while (++i <= n)
		pipe(fds[i]);
}

void	ft_pipe(t_node *node, t_env **envir)
{
	int	(*fds)[2];
	int	child;
	int	i;
	int	n;

	i = -1;
	n = node_len(node);
	fds = ft_calloc(sizeof(int *), node->counts.s_pipe + 1);
	ft_filedisc_init(fds, n);
	while (++i < n)
	{
		child = fork();
		if (child == -1)
			child_error(child, i);
		else if (child == 0)
		{
			child_process(fds, i, n);
			commands(*node, envir);
			exit(1);
		}
		node = node->next;
	}
	ft_close(fds, n);
	while (wait(0) != -1)
		;
}
