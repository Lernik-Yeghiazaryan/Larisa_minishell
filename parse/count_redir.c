/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:04:31 by tyenokya          #+#    #+#             */
/*   Updated: 2023/02/20 14:26:31 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ignore_quotes(char *str, int *i)
{
	while (str && str[*i])
	{
		if (str[*i] == '\"')
		{
			while (str[++*i] && str[*i] != '\"')
				;
			++*i;
		}
		else if (str[*i] == '\'')
		{
			while (str[++*i] && str[*i] != '\'')
				++*i;
		}
		if (!str[*i])
			break ;
		++*i;
	}
}

t_node	*cut_redir(t_node *node)
{
	int	i;
	char *tmp;

	if (!node)
		return (0);
	i = 0;
	tmp = NULL;
	while (node && node->infile && node->infile[i])
	{
		tmp = ft_strcut(node->readline, node->infile[i]);
		node->readline = tmp;
		free(tmp);
		i++;
	}
	i = 0;
	while (node && node->outfile && node->outfile[i])
	{
		tmp = ft_strcut(node->readline, node->outfile[i]);
		node->readline = tmp;
		free(tmp);
		i++;
	}
	i = 0;
	while (node && node->heredoc && node->heredoc[i])
	{
		tmp = ft_strcut(node->readline, node->heredoc[i]);
		node->readline = tmp;
		free(tmp);
		i++;
	}
	i = 0;
	while (node && node->append && node->append[i])
	{
		tmp = ft_strcut(node->readline, node->append[i]);
		node->readline = tmp;
		free(tmp);
		i++;
	}
	return (node);
}
