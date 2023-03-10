/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:56:02 by tyenokya          #+#    #+#             */
/*   Updated: 2023/03/10 15:26:30 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_len(char *str, int end, int start, char *replace)
{
	int	l1;
	int	l2;

	l1 = ft_strlen(str);
	l2 = ft_strlen(replace);
	return (l1 - end + start + l2 + 1);
}

void	ddum(char *str, char *replace, int *i)
{
	int	k;

	k = 0;
	while (replace && replace[k])
	{
		str[*i] = replace[k];
		++*i;
		++k;
	}
}

char	*ft_fill(char *str, int start, int end, char *replace)
{
	int		i;
	char	*fill;

	i = -1;
	if (!str)
		return (0);
	fill = malloc(sizeof(char) * ft_len(str, end, start, replace));
	while (str && ++i < start && str[i])
		fill[i] = str[i];
	ddum(fill, replace, &i);
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
