/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:21:50 by lgalstya          #+#    #+#             */
/*   Updated: 2023/01/22 15:21:51 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	w(char *str, int cnt, int n, int tmp)
{
	while (n > 9)
	{
		str[cnt--] = (n % 10) + 48 + tmp;
		n /= 10;
		tmp = 0;
	}
	str[cnt] = n + 48;
}

static void	f(int *n, int *neg, int *tmp)
{
	if (*n == -2147483648)
	{
		*n += 1;
		*neg = -1;
		*tmp = 1;
		*n *= -1;
	}
	else if (*n < 0)
	{
		*neg = -1;
		*n = *n * -1;
		*tmp = 0;
	}
	else if (*n >= 0)
	{
		*neg = 1;
		*tmp = 0;
	}
}

static int	count(int n)
{
	int	c;

	c = 0;
	while (n > 9)
	{
		n /= 10;
		c++;
	}
	c++;
	return (c);
}

char	*ft_itoa(int n)
{
	int		flag;
	int		tmp;
	int		cnt;
	char	*str;

	f(&n, &flag, &tmp);
	cnt = count(n);
	if (flag == -1)
	{
		str = malloc((cnt + 2));
		if (!str)
			return (0);
		cnt++;
		str[0] = '-';
	}
	else
	{
		str = malloc((cnt + 1));
		if (!str)
			return (0);
	}
	str[cnt--] = '\0';
	w(str, cnt, n, tmp);
	return (str);
}
