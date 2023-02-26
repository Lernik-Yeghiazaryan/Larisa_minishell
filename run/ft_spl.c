/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:21:00 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 17:21:03 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*lcnel(char *s,	int h,	int l)
{
	char	*str;
	int		i;

	i = -1;
	str = malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	while (++i < l)
		str[i] = s[h + i];
	str[i] = 0;
	return (str);
}

static	int	gtav(char *s, char c)
{
	int	count;
	int	i;
	int	l;

	i = -1;
	count = 1;
	l = ft_strlen(s);
	while (s[++i] && s[i] == c)
		;
	while (s[--l] && s[l] == c && i < l)
		;
	if (i == ft_strlen(s))
		return (0);
	while (s[i] && i < l)
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	return (count);
}

void	*free_arr(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		free(s[i]);
		i++;
	}
	if (s)
		free(s);
	return (0);
}

char	**ft_split(char *s, char c)
{
	int		h;
	int		t;
	int		i;
	int		count;
	char	**str;

	h = 0;
	i = -1;
	count = gtav(s, c);
	str = malloc(sizeof(char *) * (count + 1));
	if (!s || !str)
		return (NULL);
	while (++i < count)
	{
		while (s[h] && s[h] == c)
			h++;
		t = h;
		while (s[t] && s[t] != c)
			t++;
		str[i] = lcnel(s, h, t - h);
		h = t;
	}
	str[i] = 0;
	return (str);
}
