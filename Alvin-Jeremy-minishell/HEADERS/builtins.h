/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:10:49 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 16:12:21 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "libft.h"
# include "env_vars.h"

int		ft_echo(char *argv[], t_shelldata *shelldata);
int		ft_cd(char *argv[], t_shelldata *shelldata);
int		ft_pwd(char *argv[], t_shelldata *shelldata);
int		ft_export(char *argv[], t_shelldata *shelldata);
int		ft_unset(char *argv[], t_shelldata *shelldata);
int		ft_env(char *argv[], t_shelldata *shelldata);
int		ft_exit(char *argv[], t_shelldata *shelldata);

#endif
