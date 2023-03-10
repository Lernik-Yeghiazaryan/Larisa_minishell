/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:36:23 by lgalstya          #+#    #+#             */
/*   Updated: 2023/03/10 18:36:25 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_clean_sp_outfile(t_node *node)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (node->outfile && node->outfile[i])
	{
		tmp = ft_strdup(node->outfile[i]);
		free(node->outfile[i]);
		node->outfile[i] = 0;
		node->outfile[i] = ft_clean_spase_between(tmp);
		free(tmp);
		tmp = NULL;
		i++;
	}
	i = 0;
}

static void	ft_clean_sp_infile(t_node *node)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (node->infile && node->infile[i])
	{
		tmp = ft_strdup(node->infile[i]);
		free(node->infile[i]);
		node->infile[i] = 0;
		node->infile[i] = ft_clean_spase_between(tmp);
		free(tmp);
		tmp = NULL;
		i++;
	}
}

static void	ft_clean_sp_append(t_node *node)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (node->append && node->append[i])
	{
		tmp = ft_strdup(node->append[i]);
		free(node->append[i]);
		node->append[i] = 0;
		node->append[i] = ft_clean_spase_between(tmp);
		free(tmp);
		tmp = NULL;
		i++;
	}
}

void	ft_clean_sp_redir(t_node *node)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (node->heredoc && node->heredoc[i])
	{
		tmp = ft_strdup(node->heredoc[i]);
		free(node->heredoc[i]);
		node->heredoc[i] = 0;
		node->heredoc[i] = ft_clean_spase_between(tmp);
		free(tmp);
		tmp = NULL;
		i++;
	}
	ft_clean_sp_append(node);
	ft_clean_sp_outfile(node);
	ft_clean_sp_infile(node);
}
