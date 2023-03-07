/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyenokya <tyenokya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:10:37 by lgalstya          #+#    #+#             */
/*   Updated: 2023/02/25 17:41:41 by tyenokya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	take_pars_val(t_node *node, t_env **envir, int in_cpy, int out_cpy)
{
	if (node->counts.s_pipe > 0)
	{
		ft_pipe(node, envir);
	}
	else
		commands(*node, envir);

	dup2(in_cpy, 0);
	dup2(out_cpy, 1);
}

void	shlvl(t_env **en)
{
	t_env	*curr;
	char	*value;

	curr = *en;
	value = NULL;
	while (curr)
	{
		if (!ft_strcmp(curr->key, "SHLVL"))
		{
			value = ft_strdup(curr->value);
			free(curr->value);
			curr->value = ft_itoa(ft_atoi(value) + 1);
			free(value);
		}
		curr = curr->next;
	}
}

void free_node(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node->next;
		if (node->heredoc)
		{
			printf("LALALALAL\n");
			free_arr(node->heredoc);
		}
		if (node->append)
			free_arr(node->append);
		if (node->outfile)
			free_arr(node->outfile);
		if (node->infile)
			free_arr(node->infile);
		if (node->cmd)
			free_arr(node->cmd);
		if (node->readline)
			free(node->readline);
		free(node);
		node = NULL;
		node = tmp;
	}
	// free(node);
}

void	readline_main(t_node *node, t_env *envir, int in_cpy, int out_cpy)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = readline(ESC_GREEN"💚 minishell :"ESC_WHITE);
		if (!line)
			ft_print_exit();
		if (line[0])
			add_history(line);
		else
		{
			free(line);
			continue ;
		}
		lexer(&node, line, &envir);
		free(line);
		line = NULL;
		if (!node)
			continue ;
		node = parser(node, &envir);
		if (!node)
			continue ;
		take_pars_val(node, &envir, in_cpy, out_cpy);
		free_node(node);
	}
}

int	second_hook(void)
{
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_node	*node;
	t_env	*envir;
	int		in_cpy;
	int		out_cpy;

	(void)argv;
	(void)argc;
	rl_catch_signals = 0;
	rl_event_hook = second_hook;
	rl_done = 1;
	signal(SIGINT, &handler);
	signal(SIGQUIT, SIG_IGN);
	envir = NULL;
	node = NULL;
	in_cpy = dup(0);
	out_cpy = dup(1);
	environments(env, &envir);
	shlvl(&envir);
	readline_main(node, envir, in_cpy, out_cpy);
	close(out_cpy);
	close(in_cpy);
	return (0);
}
