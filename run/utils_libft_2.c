/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasargsy <vasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:19:47 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/06 17:36:21 by lgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen (s));
}

long long	ft_atoi(char *str)
{
	long	c;
	long	min;
	long	n;

	c = 0;
	min = 1;
	n = 0;
	if (!str)
		return (0);
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' ')
		c++;
	if (str[c] == '-')
		min = -1;
	if (str[c] == '+' || str[c] == '-')
		c++;
	while (str[c] >= '0' && str[c] <= '9')
	{
		n = (str[c] - '0') + (n * 10);
		c++;
	}
	return (n * min);
}

int	print_exit_code(t_env **en)
{
	printf("%d", get_exit_code(en));
	return (0);
}

void	update_list_item(t_env **lst, char *key, char *value)
{
	t_env	*curr;

	curr = *lst;
	while (curr)
	{
		if (!ft_strcmp(key, curr->key))
		{
			curr->value = value;
			return ;
		}
		curr = curr->next;
	}
}
