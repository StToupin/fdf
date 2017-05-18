/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:09:46 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/18 11:14:33 by stoupin          ###   ########.fr       */
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

int			print_width_error(int line_number, int w, int expected_w)
{
	ft_putstr_fd("Line ", 2);
	ft_putnbr_fd(line_number, 2);
	ft_putstr_fd(" is of len ", 2);
	ft_putnbr_fd(w, 2);
	ft_putstr_fd(" instead of ", 2);
	ft_putnbr_fd(expected_w, 2);
	ft_putstr_fd("!\n", 2);
	return (1);
}

int			load_file(t_env *env, int fd)
{
	char	*line;
	int		n_last_line;
	t_ilist	ilist;

	env->dim = (t_coord2){0, 0};
	ilist_create(&ilist);
	env->dim.x = -1;
	while (get_next_line(&(env->allocated), fd, &line) == 1)
	{
		if (line[0] == '\0')
			continue ;
		n_last_line = env->dim.x;
		env->dim.x = count_numbers(line);
		if (n_last_line != env->dim.x && n_last_line != -1)
			return (print_width_error(env->dim.y + 1, env->dim.x, n_last_line));
		if (ilist_push_front(&(env->allocated), &ilist, line, env->dim.x))
			return (1);
		env->dim.y++;
		my_malloc_free(&(env->allocated), line);
	}
	if (env->dim.x == -1 || !(env->map = ilist_join(&(env->allocated), &ilist)))
		return (1);
	if (env->dim.y > 0)
		calc_extremums(env);
	return (0);
}
