/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:41:37 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 17:33:57 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_oldpwd(char *path, t_env **en)
{
	t_env	*new_env;

	new_env = malloc(sizeof(t_env));
	if (!search_list(*en, "OLDPWD"))
	{
		ft_inint_env("OLDPWD", path, new_env);
		ft_lstadd_back_env(en, new_env);
	}
	else
		update_list_item(en, "OLDPWD", path);
}

static int	cd_home(t_env**en)
{
	if (!chdir(search_list(*en, "HOME")))
	{
		add_oldpwd(search_list(*en, "HOME"), en);
		return (0);
	}
	return (-1);
}

static int	cd_old(t_env **en, int st)
{
	if (search_list(*en, "OLDPWD") == 0)
	{
		printf("cd: OLDPWD not set\n");
		set_exit_code("1", en);
	}
	else
	{
		if (!chdir(search_list(*en, "OLDPWD")))
		{
			add_oldpwd(search_list(*en, "OLDPWD"), en);
			st = cmd_pwd(en);
			return (st);
		}
		return (-1);
	}
	return (0);
}

int	cmd_cd(t_node node, t_env **en)
{
	char	*path;
	int		st;

	st = 0;
	if ((!node.cmd[1]) || !ft_strcmp(node.cmd[1], "~"))
		return (cd_home(en));
	else if (!ft_strcmp(node.cmd[1], "-"))
		return (cd_old(en, st));
	else if (node.cmd[1])
	{
		path = get_current_path();
		add_oldpwd(path, en);
		if (!chdir(node.cmd[1]))
			return (0);
			// set_exit_code("0", en);
		else
			return (-1);
			// set_exit_code("1", en);
	}
	return (0);
}
