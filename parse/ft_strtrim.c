/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:02:15 by tyenokya          #+#    #+#             */
/*   Updated: 2023/03/10 15:59:46 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	gtav(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	first(char *s, char *set)
{
	int	i;

	i = 0;
	while (gtav(set, s[i]) == 1)
	{
		i++;
	}
	return (i);
}

int	last(char *s, char *set)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (gtav(set, s[i]) == 1 && i > 0)
	{
		i--;
	}
	return (i);
}

void	small(char *s1, char *trim, int *f, char c)
{	
	if (ft_strlen(s1) != ft_strlen(trim))
		(*f) = 1;
	if (is_space(c))
		*f = 0;
}

char	*ft_strtrim(char *s1, char *set, int *f)
{
	int		i;
	int		start;
	char	*trim;
	int		len;

	i = 0;
	*f = 0;
	if (last(s1, set) == 0 && first(s1, set) == ft_strlen(s1))
		len = 1;
	else
		len = last(s1, set) - first(s1, set) + 1;
	trim = malloc(len + 1);
	if (!trim)
		return (0);
	start = first(s1, set);
	while (s1[start] && i < len)
	{
		trim[i] = s1[start];
		i++;
		start++;
	}
	trim[i] = '\0';
	small(s1, trim, f, set[0]);
	free(s1);
	return (trim);
}
