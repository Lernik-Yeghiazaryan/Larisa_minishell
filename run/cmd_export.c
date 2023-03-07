/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <lgalstya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:59:41 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/22 12:01:33 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	equal_only(char **array, t_env **en)
{
	t_env	*new_node;
	t_env	*curr;
	int		flag;

	flag = 0;
	curr = *en;
	while (curr)
	{
		if (!ft_strcmp(curr->key, array[0]))
		{
			if (array[1] != NULL && ft_strcmp(curr->value, array[1]) != 0)
			{
				free(curr->value);
				curr->value = ft_strdup(array[1]);
			}
			flag = 1;
		}
		curr = curr->next;
	}
	if (!array[1])
		array[1] = ft_strdup("");
	if (!flag)
	{
		new_node = malloc(sizeof(t_env));
		ft_inint_env(array[0], array[1], new_node);
		ft_lstadd_back_env(en, new_node);
	}
	// free_arr(array);
}

void	pluse_equal(char **array, t_env **en)
{
	int		flag;
	t_env	*curr;
	// char 	*tmp;

	flag = 0;
	// tmp = NULL;
	curr = *en;
	if (!array[1])
		array[1] = ft_strdup("");
	while (curr)
	{
		if (!ft_strcmp(curr->key, array[0]))
		{
			// curr->value  = ft_strjoin(curr->value, array[1]);
			curr->value = ft_strjoin(curr->value, array[1]);
			// curr->value = tmp;
			// free(tmp);
			// tmp = NULL;
			flag = 1;
		}
		curr = curr->next;
		if (flag)
			return ;
		if (!curr && !flag)
			equal_only(array, en);
	}
	// free_arr(array);
}

static void	add_only(char *array, t_env **en)
{
	t_env	*new_node;
	t_env	*curr;
	int		flag;

	flag = 0;
	curr = *en;
	while (curr)
	{
		if (!ft_strcmp(curr->key, array))
			flag = 1;
		curr = curr->next;
	}
	if (!flag)
	{
		new_node = malloc(sizeof(t_env));
		ft_inint_env(array, NULL, new_node);
		ft_lstadd_back_env(en, new_node);
	}
}

static void	cmd_one_export(char *cmd, t_env **en)
{
	char	**array;

	array = NULL;
	if (!check_valid_identif(cmd, en) || (cmd[0] > 47 && cmd[0] < 58))
	{
		printf("export: `%s': not a valid identifier\n", cmd);
		set_exit_code("1", en);
		return ;
	}
	else if (ft_strnstr(cmd, "+=", ft_strlen(cmd)))
	{
		pluse_equal_2(cmd, en);
	}
	else if (ft_strnstr(cmd, "=", ft_strlen(cmd)))
	{
		array = ft_split_export(cmd, '=');
		equal_only(array, en);
		if (array[0])
			free(array[0]);
		if (array[1])
			free(array[1]);
		free(array);
		array = NULL;
	}
	else
		add_only(cmd, en);
}

void	cmd_export(t_node node, t_env **en)
{
	int	i;

	i = 1;
	if (!node.cmd[1])
	{
		sort_list(en);
		// set_exit_code("0", en);
		return ;
	}
	while (node.cmd[i])
	{
		cmd_one_export(node.cmd[i], en);
		i++;
	}
}
