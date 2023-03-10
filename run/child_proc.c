/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:06:39 by lgalstya          #+#    #+#             */
/*   Updated: 2023/03/10 18:06:42 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hidden_file(char **cmd)
{
	char	*tmp;

	tmp = NULL;
	if ((*cmd[0]) != '.')
	{
		tmp = ft_strjoin("/", *cmd);
		free(*cmd);
		(*cmd) = tmp;
	}
}

char	*accses_to_exec(char *cmd, char *path)
{
	int		i;
	char	**token;
	char	*cmd_accs;

	i = 0;
	token = ft_split(path, ':');
	hidden_file(&cmd);
	while (token[i])
	{
		cmd_accs = ft_strjoin(token[i], cmd);
		if (access(cmd_accs, 0) == 0)
			return (cmd_accs);
		else
		{
			free(cmd_accs);
			cmd_accs = NULL;
		}
		i++;
	}
	free_arr(token);
	return (cmd);
}

int	child_proc(t_node node, t_env **envir, char **ch_env)
{
	char	*path;
	char	*cmd;
	int		ret;

	cmd = NULL;
	rl_catch_signals = 0;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, SIG_IGN);
	ret = 0;
	path = search_list(*envir, "PATH");
	if (!path)
		not_found_error(node.cmd[0]);
	if (node.cmd && node.cmd[0])
		cmd = accses_to_exec(node.cmd[0], path);
	if (node.cmd && node.cmd[0] != NULL
		&& (node.cmd[0][0] == '/' || node.cmd[0][0] == '.'))
		ret = execve(node.cmd[0], node.cmd, ch_env);
	else if (node.cmd && node.cmd[0])
		ret = execve(cmd, node.cmd, ch_env);
	if (ret == -1 && node.cmd && node.cmd[0])
		not_found_error(node.cmd[0]);
	free(cmd);
	cmd = NULL;
	return (ret);
}
