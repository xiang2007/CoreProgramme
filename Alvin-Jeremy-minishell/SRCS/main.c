/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 11:54:32 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/30 10:19:54 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_vars.h"
#include "parsing.h"
#include "token.h"
#include "heredoc.h"
#include "execution.h"
#include "ft_signals.h"

static t_ast	*parse(char *input, t_shelldata *shelldata)
{
	t_tokendata	tokendata;
	t_token		*token_cursor;
	t_ast		*ast;

	add_history(input);
	ft_bzero(&tokendata, sizeof(t_tokendata));
	tokendata.input = input;
	if (tokenize(&tokendata) == SUCCESS)
	{
		token_cursor = tokendata.token_lst;
		ast = build_ast(&token_cursor, 0);
		if (!ast)
			set_env_var(&shelldata->env_vars, "?=2");
		if (ast && open_heredocs(ast, shelldata) != 0)
		{
			free_ast(ast);
			ast = NULL;
		}
	}
	else
		ast = NULL;
	free(input);
	free_tokens(tokendata.token_lst);
	return (ast);
}

static void	parse_and_execute(char *input, t_shelldata *shelldata)
{
	shelldata->ast_head = parse(input, shelldata);
	if (DEBUG)
		print_ast(shelldata->ast_head, 0);
	if (execute_ast(shelldata->ast_head, shelldata) == ERFATAL)
	{
		ft_putstr_fd("Fatal error. Exiting\n", 2);
		clean_exit(shelldata, 255);
	}
	if (sigint_check())
		set_env_var(&shelldata->env_vars, "?=130");
	else if (sigquit_check())
		set_env_var(&shelldata->env_vars, "?=131");
	reset_signals();
	free_ast(shelldata->ast_head);
	close_heredocs(shelldata->heredoc_fds);
}

static char	*get_input(t_shelldata *shelldata)
{
	char	*input;
	char	*temp;

	if (shelldata->interactive_mode)
		return (readline(PROMPT));
	temp = get_next_line(0);
	input = ft_strtrim(temp, "\n");
	free(temp);
	return (input);
}

static void	run_shell(t_shelldata *shelldata)
{
	char	*input;

	while (1)
	{
		setup_idle_signals();
		input = get_input(shelldata);
		shelldata->line_count++;
		if (sigint_check())
		{
			shelldata->line_count += sigint_check();
			set_env_var(&shelldata->env_vars, "?=130");
		}
		reset_signals();
		if (!input)
			break ;
		if (!*input)
		{
			free(input);
			continue ;
		}
		setup_nonidle_signals();
		parse_and_execute(input, shelldata);
	}
}

//add rl_outstream = stderr; for better non interactive mode behaviour
int	main(int argc, char *argv[], char *envp[])
{
	t_shelldata	shelldata;
	int			exit_code;

	(void)argc;
	(void)argv;
	ft_bzero(shelldata.heredoc_fds, FD_MAX * sizeof(int));
	shelldata.env_vars = create_env(envp);
	init_shell_env(&shelldata.env_vars);
	shelldata.head_shell = 1;
	rl_outstream = stderr;
	if (isatty(0) && isatty(2))
		shelldata.interactive_mode = 1;
	else
		shelldata.interactive_mode = 0;
	shelldata.line_count = 0;
	run_shell(&shelldata);
	exit_code = ft_atoi(fetch_env_var_value(shelldata.env_vars, "?"));
	ft_lstclear(&shelldata.env_vars, free);
	rl_clear_history();
	if (shelldata.interactive_mode)
		ft_putstr_fd("exit\n", 2);
	return (exit_code);
}
