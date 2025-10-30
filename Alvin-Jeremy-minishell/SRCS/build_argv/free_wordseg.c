/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_wordseg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:08:39 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/14 17:03:49 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build_argv.h"

void	free_wordseg(void *ptr)
{
	t_wordseg	*wordseg;

	wordseg = (t_wordseg *)ptr;
	if (!wordseg)
		return ;
	if (wordseg->str)
		free(wordseg->str);
	free(wordseg);
}
