/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:09:46 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/10 14:10:12 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

int	load_file(t_env *env, int fd)
{
	char	*line;
	int		n_numbers;

	env->width = -1;
	env->height = 0;
	while (get_next_line(&(env->allocated), fd, &line) == 1)
	{
		n_numbers = count_numbers(line);
		if (env->width == -1)
			env->width = n_numbers;
		else if (n_numbers != env->width)
			return (1);
		env->height++;
		my_malloc_free(&(env->allocated), line);
	}
	return (0);
}
