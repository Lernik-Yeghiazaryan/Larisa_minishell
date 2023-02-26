/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:51:29 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/18 17:05:32 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
		}
		if (s1[i] == '\0')
			return ((-1) * s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strrchr(char *s, int c)
{
	char	*ret;

	ret = 0;
	if (c == 0)
		return ((char *)s + ft_strlen (s));
	if (c < 0 || c > 127)
		return ((char *)s);
	while (*s)
	{
		if (*s == c)
			ret = (char *)s;
		s++;
	}
	return (ret);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*s2;
	int		count;
	int		end;

	end = 0;
	count = ft_strlen(s);
	if (!*s || !s)
		return (0);
	if (start < count)
		end = count - start;
	if (end > len)
		end = len;
	s2 = (char *)malloc(sizeof(char) * (end + 1));
	if (!s2)
		return (0);
	ft_strlcpy(s2, s + start, end + 1);
	return (s2);
}

int	ft_strlcpy(char *dst, char *src, int l)
{
	int	i;

	i = 0;
	if ((! dst && src) || l == 0)
		return (ft_strlen (src));
	if (!dst && !src)
		return (0);
	while (i < l - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
