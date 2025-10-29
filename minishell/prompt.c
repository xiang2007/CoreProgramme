/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:06:37 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/28 17:30:52 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	execute_child(char **prompt, t_data *data)
// {
// 	int		status;
// 	char	*path;

// 	(void)data;
// 	path = ft_getpath(*prompt, data->env);
// 	if (access(path, X_OK))
// 	{
// 		printf("executing cmd");
// 		execve(prompt[0], prompt, data->env);
// 		wait(&status);
// 	}
// }

// void	execute_prompt(char **prompt, t_data *data)
// {
// 	pid_t	id;

// 	id = fork();
// 	if (id == 0)
// 		execute_child(prompt, data);
// }


// int	main(int ac, char **av, char **env)
// {
// 	t_data	*data;
// 	char	**prompt = NULL;

// 	data = malloc(sizeof(t_data));
// 	(void)ac;
// 	(void)av;
// 	data->env = env;
// 	while (1)
// 	{
// 		*prompt = readline("---> ");
// 		if (strstr(*prompt, "exit"))
// 			break ;
// 		execute_prompt(prompt, data);
// 		printf("%s\n", *prompt);
// 		add_history(*prompt);
// 		free (prompt);
// 	}
// 	rl_clear_history();
// 	free (prompt);
// 	return (0);
// }