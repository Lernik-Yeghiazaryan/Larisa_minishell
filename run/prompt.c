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

char	*accses_to_exec(char *cmd, char *path)
{
	int		i;
	char	**token;
	char	*cmd_accs;
	char	*tmp;

	i = 0;
	tmp = NULL;
	token = ft_split(path, ':');
	if (cmd[0] != '.')
	{
		tmp = ft_strjoin("/", cmd);
		cmd = tmp;
		// free(tmp);
		// tmp = NULL;
	}
	while (token[i])
	{
		cmd_accs = ft_strjoin(token[i], cmd);
		// cmd_accs = tmp;
		// free(tmp);
		// tmp = NULL;
		// printf("cmd = %s\n", cmd);
		// printf("token[%d] = %s\n", i, token[i]);
		// printf("cmd_accs = %s\n", cmd_accs);
		if (access(cmd_accs, 0) == 0)
			return (cmd_accs);
		else
		{
			//es em avlacrel
			free(cmd_accs);
			cmd_accs = NULL;
		}
		i++;
	}
	free_arr(token);
	return (cmd);
}

static int	child_proc(t_node node, t_env **envir, char **ch_env)
{
	char	*path;
	char	*cmd;
	int		ret;

	rl_catch_signals = 0;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, SIG_IGN);
	ret = 0;
	path = search_list(*envir, "PATH");
	cmd = accses_to_exec(node.cmd[0], path);
	if (node.cmd[0][0] == '/' || node.cmd[0][0] == '.')
		ret = execve(node.cmd[0], node.cmd, ch_env);
	else
		ret = execve(cmd, node.cmd, ch_env);
	if (ret == -1)
		not_found_error(node.cmd[0], envir);
	// free(cmd);
	// cmd = NULL;
	return (ret);
}

void	status_wait(int status, int exec_status, t_env **en)
{
	char *str;

	str = ft_itoa(WEXITSTATUS(status));
	// printf("str = %s\n", str);
	if (WIFEXITED(status) && exec_status == 0)
		set_exit_code(str, en);
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	exit_for_norm(t_env **env)
{
	set_exit_code("127", env);
	exit(127);
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
	if (is_builtin(node.cmd[0]))
		exec_status = builtin(node, envir);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			exec_status = child_proc(node, envir, ch_env);
			if (exec_status < 0)
				exit_for_norm(envir);
		}
		wait(&status);
		status_wait(status, exec_status, envir);
		signal(SIGINT, &handler);
		signal(SIGQUIT, SIG_IGN);
	}
	free_arr(ch_env);
	return (exec_status);
}
