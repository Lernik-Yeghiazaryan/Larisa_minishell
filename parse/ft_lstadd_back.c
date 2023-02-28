/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:17:43 by tyenokya          #+#    #+#             */
/*   Updated: 2023/02/03 17:41:00 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_list_add_back(t_node **lst, t_node *new)
{
	t_node	*testnode;

	if (*lst == NULL)
		*lst = new;
	else
	{
		testnode = *lst;
		while (testnode->next != NULL)
			testnode = testnode->next;
		testnode->next = new;
		// testnode->next->next = NULL;
	}
}
