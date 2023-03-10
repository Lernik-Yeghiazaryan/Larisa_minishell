/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:35:53 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/09 17:35:57 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_str(char *cmd)
{	
	if (cmd != NULL)
	{
		free(cmd);
		cmd = 0;
	}
}

void	free_one_node(t_node node)
{
	if (node.heredoc)
		free_arr(node.heredoc);
	if (node.append)
		free_arr(node.append);
	if (node.outfile)
		free_arr(node.outfile);
	if (node.infile)
		free_arr(node.infile);
	if (node.cmd)
		free_arr(node.cmd);
	if (node.readline)
		free(node.readline);
}

void	free_node(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node->next;
		if (node->heredoc)
			free_arr(node->heredoc);
		if (node->append)
			free_arr(node->append);
		if (node->outfile)
			free_arr(node->outfile);
		if (node->infile)
			free_arr(node->infile);
		if (node->cmd)
			free_arr(node->cmd);
		if (node->readline)
			free(node->readline);
		free(node);
		node = NULL;
		node = tmp;
	}
}
