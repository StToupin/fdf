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
#include "ilist.h"

static void	calc_extremums(t_env *env)
{
	int x;
	int y;

	env->z_min = env->map[0][0];
	env->z_max = env->map[0][0];
	y = 0;
	while (y < env->dim.y)
	{
		x = 0;
		while (x < env->dim.x)
		{
			if (env->map[y][x] < env->z_min)
				env->z_min = env->map[y][x];
			if (env->map[y][x] > env->z_max)
				env->z_max = env->map[y][x];
			x++;
		}
		y++;
	}
}

int			load_file(t_env *env, int fd)
{
	char	*line;
	int		n_numbers;
	t_ilist	ilist;
	int		err;

	env->dim = (t_coord2){-1, 0};
	ilist_create(&ilist);
	while (get_next_line(&(env->allocated), fd, &line) == 1)
	{
		if (line[0] == '\0')
			continue ;
		n_numbers = count_numbers(line);
		if (env->dim.x == -1)
			env->dim.x = n_numbers;
		else if (n_numbers != env->dim.x)
			return (1);
		err = ilist_push_front(&(env->allocated), &ilist, line, n_numbers);
		if (err)
			return (err);
		env->dim.y++;
		my_malloc_free(&(env->allocated), line);
	}
	env->map = ilist_join(&(env->allocated), &ilist);
	calc_extremums(env);
	return (0);
}
