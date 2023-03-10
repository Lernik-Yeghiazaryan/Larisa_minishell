/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:34:10 by tyenokya          #+#    #+#             */
/*   Updated: 2023/03/10 14:26:40 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	initial_nodes(t_node *node)
{
	int	i;

	i = 0;
	node->cmd = NULL;
	while (node->readline && node->readline[i])
	{
		if (node->readline[i] == '\"' || node->readline[i] == '\'')
			ignore_quotes(node->readline, &i);
		if (!node->readline[i])
			break ;
		if (node->readline[i] == '>' && node->readline[i + 1] == '>')
			put_hd_app(node, '>');
		else if (node->readline[i] == '<' && node->readline[i + 1] == '<')
			put_hd_app(node, '<');
		else if (node->readline[i] == '>' && node->readline[i + 1] != '>')
			put_in_out(node, '>');
		else if (node->readline[i] == '<' && node->readline[i + 1] != '<')
			put_in_out(node, '<');
		++i;
	}
	node = cut_redir(node);
	if (node->readline)
		node->cmd = pars_ft_split(node->readline, ' ');
	return (1);
}
