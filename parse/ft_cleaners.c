/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaners.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:33:18 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/25 18:00:14 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_clean(char **str, t_env **envir)
{
	int	i;
	int	f;
	int	t;

	i = 0;
	f = 0;
	t = 0;
	while (str && str[i])
	{
		str[i] = ft_strtrim(str[i], SPACES, &f);
		str[i] = ft_strtrim(str[i], "\'", &t);
		if (t)
		{
			++i;
			continue ;
		}
		str[i] = ft_strtrim(str[i], "\"", &f);
		str[i] = change_doll(str[i], envir);
		i++;
	}
	return (str);
}

void	ft_clean_spasec(t_node *head, t_env **envir)
{
	t_node	*node;

	node = head;
	while (node)
	{
		node->cmd = ft_clean(node->cmd, envir);
		node->infile = ft_clean(node->infile, envir);
		node->outfile = ft_clean(node->outfile, envir);
		node->append = ft_clean(node->append, envir);
		node->heredoc = ft_clean(node->heredoc, envir);
		node = node->next;
	}
}

char	*ft_clean_spase_between(char *str)
{
	int		i;
	char	*res;
	char	*temp;
	int		start;

	i = -1;
	start = 0;//es toxy indz tvuma kareliya jnjelel
	temp = NULL;
	res = NULL;
	while (str && str[++i])
	{
		start = i;
		while (str[i] && is_space(str[i]))
			i++;
		res = ft_substr(str, 0, start);
		temp = ft_substr(str, i, ft_strlen(str) - i);
		res = ft_strjoin(res, temp);
		free(temp);
	}
	return (res);
}

static void	ft_clean_sp_redir_2(t_node *node)
{
	int	i;

	i = 0;
	while (node->outfile && node->outfile[i])
	{
		node->outfile[i] = ft_clean_spase_between(node->outfile[i]);
		i++;
	}
	i = 0;
	while (node->infile && node->infile[i])
	{
		node->infile[i] = ft_clean_spase_between(node->infile[i]);
		i++;
	}
}

void	ft_clean_sp_redir(t_node *node)
{
	int	i;

	i = 0;
	while (node->heredoc && node->heredoc[i])
	{
		node->heredoc[i] = ft_clean_spase_between(node->heredoc[i]);
		i++;
	}
	i = 0;
	while (node->append && node->append[i])
	{
		node->append[i] = ft_clean_spase_between(node->append[i]);
		i++;
	}
	ft_clean_sp_redir_2(node);
}
