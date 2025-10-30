/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_argv.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:47:35 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 16:11:29 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_ARGV_H
# define BUILD_ARGV_H

# include <dirent.h>
# include <stdbool.h>
# include "env_vars.h"

//COMPOUND includes quoted literals and quoted env vars
//a single COMPOUND wordseg expand to a single LITERAL wordseg
//delimiter wordsegs will be a linked list node with content == NULL
typedef enum e_wordseg_type
{
	LITERAL,
	ENV_VAR,
	WILDCARD,
}	t_wordseg_type;

typedef struct s_wordseg
{
	t_wordseg_type	type;
	char			*str;
	bool			quoted;
}	t_wordseg;

t_list		*create_wordlst(char **strarr, t_list *env_vars);
void		expand_wordlst_env_var(t_list **wordlst, t_list *env_vars);
void		expand_wordlst_wildcard(t_list **wordlst, int export_on);
char		**get_matching_filenames(t_list *wildcard);
int			match_wildcard(t_list *wildcard, char *str);
void		free_wordseg(void *wordseg);

//utils
int			is_valid_env_var_exp(char *arg);
int			count_var_exp_len(char *arg);
int			has_wildcard(t_list *wordlst, int export_on);

//create_wordsegs
t_wordseg	*create_wildcard_wordseg(char **str_ptr);
t_wordseg	*create_env_var_wordseg(char **str_ptr);
t_wordseg	*create_expanded_literal_wordseg(char **str_ptr, t_list *env_vars);
t_wordseg	*create_literal_wordseg(char **str_ptr);

//utils for create_expanded_literal_wordseg()
void		handle_double_quote(char **newstr_ptr, char **str_ptr,
				t_list *env_vars);
void		handle_single_quote(char **newstr_ptr, char **str_ptr);
void		handle_unquoted(char **newstr_ptr, char **str_ptr);

#endif
