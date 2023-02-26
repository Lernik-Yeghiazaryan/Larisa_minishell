/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:39:38 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 17:33:41 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "pwd") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}

int	builtin(t_node node, t_env **en)
{
	int	status;

	status = -1;
	if (!ft_strcmp(node.cmd[0], "echo"))
	{
		cmd_echo(node, en);
		set_exit_code("0", en);
	}	
	else if (!ft_strcmp(node.cmd[0], "cd"))
		cmd_cd(node, en);
	else if (!ft_strcmp(node.cmd[0], "pwd"))
		cmd_pwd(en);
	else if (!ft_strcmp(node.cmd[0], "export"))
		cmd_export(node, en);
	else if (!ft_strcmp(node.cmd[0], "unset"))
		cmd_unset(node.cmd[1], en);
	else if (!ft_strcmp(node.cmd[0], "env"))
		print_list(en);
	else if (!ft_strcmp(node.cmd[0], "exit"))
	{
		status = 1;
		cmd_exit(node.cmd, en);
	}
	return (status);
}
