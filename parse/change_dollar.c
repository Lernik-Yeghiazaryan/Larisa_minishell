/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:44:13 by tyenokya          #+#    #+#             */
/*   Updated: 2023/02/25 17:20:48 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_fill(char *str, int start, int end, char *replace)
{	
	int		i;
	int		k;
	char	*fill;

	k = 0;
	i = 0;
	if (!str)
		return (0);
	fill = malloc(sizeof(char) * (ft_strlen(str) - (end - start) + ft_strlen(replace) + 1));
	while (str && str[i] && i < start)
	{
		fill[i] = str[i];
		++i;
	}
	while (replace && replace[k])
	{
		fill[i] = replace[k];
		++i;
		++k;
	}
	while (str && str[end])
	{
		fill[i] = str[end];
		++i;
		++end;
	}
	fill[i] = '\0';
	free(str);
	return (fill);
}

static char	*replace(char *str,int start, int end, t_env *en)
{
	char	*s;
	
	s = ft_substr(str, start, end - start + 1);
	while (en)
	{
		if (!ft_strcmp(en->key, s))
		{
			free(s);
			return (en->value);
		}
		en = en->next;
	}
	if (!ft_strcmp("?", s))
	{
		free(s);
		return ("0");
	}
	free (s);
	return (NULL);
}

int	print_doll(char *str, int *i)
{
	if (str[*i] == '$' && (!str[*i + 1] || (is_space(str[*i]))))
	{
		i++;
		return (1);
	}
	return (0);
}

static int check_afterelem1(char c)
{
	if (c && (c == '_' || ft_isalpha(c) || c == '?'))
		return (0);
	return (1);
}

static int check_afterelem2(char c)
{
	if (c && c != '\'' && c != '\"' && c != ' ' && (c != '$' || !is_meta(c)))
		return (0);
	return (1);
}

char	*change_doll(char *str, t_env **en)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	while (str && str[i])
	{
		print_doll(str, &i);
		if (str[i] == '$' && !check_afterelem1(str[i + 1]))
		{
			start = i;
			if (str[i] && !print_doll(str, &i))
			{
				++i;
				while (str[i] && !check_afterelem2(str[i + 1]))
					++i;
				end = i;
				str = ft_fill(str, start, end + 1, replace(str, start + 1, end, *en));
				i = 0;
			}
		}
		if (!str || !str[i])
			break ;
		i++;
	}
	return (str);
}
