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
		// printf("str[%d] = %s\n", i, str[i]);
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
		if (node->cmd)
			node->cmd = ft_clean(node->cmd, envir);
		if (node->infile[0])
			node->infile = ft_clean(node->infile, envir);
		if (node->outfile[0])
			node->outfile = ft_clean(node->outfile, envir);
		if (node->append[0])
			node->append = ft_clean(node->append, envir);
		if (node->heredoc[0])
			node->heredoc = ft_clean(node->heredoc, envir);
}

char	*ft_clean_spase_between(char *str)
{
	int		i;
	char	*res;
	char	*res_temp;
	char	*temp;
	int		start;

	i = -1;
	start = 0;
	temp = NULL;
	res = NULL;
	while (str && str[++i])
	{
		start = i;
		while (str[i] && is_space(str[i]))
			i++;
		res_temp = ft_substr(str, 0, start);
		temp = ft_substr(str, i, ft_strlen(str) - i);
		res = ft_strjoin(res_temp, temp);
		if (res && str[i] && str[i + 1])
			free(res);
		free(temp);
		free(res_temp);
	}
	return (res);
}

static void	ft_clean_sp_redir_2(t_node *node)
{
	int	i;
	char *tmp;

	i = 0;
	tmp = NULL;
	// printf("ka3 = %s\n", node->outfile[0]);
	while (node->outfile && node->outfile[i])
	{
		// printf("before outfile = %s\n", node->outfile[i]);
		tmp = ft_strdup(node->outfile[i]);
		free(node->outfile[i]);
		node->outfile[i] = 0;
		node->outfile[i] = ft_clean_spase_between(tmp);
		free(tmp);
		tmp = NULL;
		// printf("after outfile = %s\n", node->outfile[i]);
		i++;
	}
	i = 0;
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
	i = 0;
	while (node->append && node->append[i])
	{
		// printf("before append = %s\n", node->append[i]);
		tmp = ft_strdup(node->append[i]);
		free(node->append[i]);
		node->append[i] = 0;
		node->append[i] = ft_clean_spase_between(tmp);
		free(tmp);
		tmp = NULL;
		// printf("after append = %s\n", node->append[i]);
		i++;
	}
	ft_clean_sp_redir_2(node);
}
