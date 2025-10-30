/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:10:49 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 16:11:53 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VARS_H
# define ENV_VARS_H

# include "libft.h"

//environment variable handling
t_list	*create_env(char *envp[]);
void	init_shell_env(t_list **env_vars);
char	**env_to_array(t_list *env_vars);
char	*fetch_env_var_value(t_list *env_vars, char *var_name);
char	*fetch_env_var_value_n(t_list *env_vars, char *var_name, size_t n);
void	set_env_var(t_list **env_vars, char *env_var_str);
void	rm_env_var(t_list **env_vars, char *var_name);
void	filter_env_array(char **env_array);
void	print_filtered_env(t_list *env_vars);
void	print_formatted_env(t_list *env_vars);

#endif
