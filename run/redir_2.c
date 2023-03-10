/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:18:14 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/25 15:42:14 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_heredoc(t_node *node)
{
	int	i;

	i = -1;
	if (*node->heredoc)
	{
		while (node->heredoc[++i])
		{
			if (i == ft_arrlen(node->heredoc) - 1)
				heredoc(node->heredoc[i]);
			else
				heredoc_not(node->heredoc[i]);
		}
	}
}

void	ft_infile(t_node *node)
{
	int	i;

	i = -1;
	if (*node->infile)
	{
		while (node->infile[++i])
		{
			if (i == ft_arrlen(node->infile) - 1)
			{
				printf("%s\n", node->infile[i]);
				cmd_infile(node->infile[i], node);
			}
			else
				cmd_no_infile(node->infile[i], node);
		}
	}
}

void	ft_outfile(t_node *node)
{
	int	i;

	i = -1;
	if (*node->outfile)
	{
		while (node->outfile[++i])
		{
			if (i == ft_arrlen(node->outfile) - 1)
				cmd_outfile(node->outfile[i], 1);
			else
				cmd_outfile(node->outfile[i], 0);
		}
	}
}

void	ft_append(t_node *node)
{
	int	i;

	i = -1;
	if (*node->append)
	{
		while (node->append[++i])
		{
			if (i == ft_arrlen(node->append) - 1)
				cmd_append(node->append[i], 1);
			else
				cmd_append(node->append[i], 0);
		}
	}
}

void	ft_redirs(t_node *node)
{
	node->inf_err_code = 0;
	node->inf_stat = 0;
	ft_heredoc(node);
	ft_infile(node);
	ft_outfile(node);
	ft_append(node);
}
