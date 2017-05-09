/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 14:51:31 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/05 14:51:34 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "coordinates.h"
#include "mlx.h"

/*
** Bresenham's line algorithm
*/

static inline double	ft_abs(double x)
{
	if (x < 0.)
		return (-x);
	else
		return (x);
}

static inline int		ft_iabs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

static int				draw_line_not_sloppy(t_env *env,
												t_coord2 c0, t_coord2 c1,
												int color)
{
	t_coord2	delta;
	double		delta_err;
	double		error;
	t_coord2	c;
	t_coord2	direction;

	delta = (t_coord2){c1.x - c0.x, c1.y - c0.y};
	delta_err = ft_abs((double)delta.y / (double)delta.x);
	error = delta_err - .5f;
	direction = (t_coord2){c1.x > c0.x ? 1 : -1, c1.y > c0.y ? 1 : -1};
	c = c0;
	while (c.x * direction.x <= c1.x * direction.x)
	{
		mlx_pixel_put(env->mlx_ptr, env->mlx_win, (int)c.x, (int)c.y, color);
		error += delta_err;
		if (error > .5f)
		{
			c.y += direction.y;
			error -= 1.f;
		}
		c.x += direction.x;
	}
	return (0);
}

static int				draw_line_sloppy(t_env *env, t_coord2 c0, t_coord2 c1,
											int color)
{
	t_coord2	delta;
	double		delta_err;
	double		error;
	t_coord2	c;
	t_coord2	direction;

	delta = (t_coord2){c1.x - c0.x, c1.y - c0.y};
	delta_err = ft_abs((double)delta.x / (double)delta.y);
	error = delta_err - .5f;
	direction = (t_coord2){c1.x > c0.x ? 1 : -1, c1.y > c0.y ? 1 : -1};
	c = c0;
	while (c.y * direction.y <= c1.y * direction.y)
	{
		mlx_pixel_put(env->mlx_ptr, env->mlx_win, (int)c.x, (int)c.y, color);
		error += delta_err;
		if (error > .5f)
		{
			c.x += direction.x;
			error -= 1.f;
		}
		c.y += direction.y;
	}
	return (0);
}

int						draw_line(t_env *env,
									t_coord2 c0, t_coord2 c1, int color)
{
	if (ft_iabs(c1.y - c0.y) > ft_iabs(c1.x - c0.x))
		draw_line_sloppy(env, c0, c1, color);
	else
		draw_line_not_sloppy(env, c0, c1, color);
	return (0);
}
