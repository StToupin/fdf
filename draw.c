/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:25:33 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/09 16:25:34 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinates.h"
#include "fdf.h"
#include "mlx.h"
#include "colors.h"

static t_coord3	get_coord(t_env *env, int x, int y)
{
	t_coord3 c;

	c.x = (double)x - (double)env->dim.x / 2.;
	c.y = (double)env->dim.y / 2. - (double)y;
	c.z = (double)env->map[y][x];
	if (env->z_max != env->z_min)
		c.z = (c.z - env->z_min) / (double)(env->z_max - env->z_min);
	return (c);
}

static void		segment3d_altitude(t_env *env, t_coord3 c0, t_coord3 c1,
								int (*fcolor)(double))
{
	t_coord2 c0_proj;
	t_coord2 c1_proj;

	c0_proj = do_projection(&(env->pm), do_scale(c0, env->scale));
	c1_proj = do_projection(&(env->pm), do_scale(c1, env->scale));
	c0_proj.x += WIN_WIDTH / 2.;
	c0_proj.y = WIN_HEIGHT / 2. - c0_proj.y;
	c1_proj.x += WIN_WIDTH / 2.;
	c1_proj.y = WIN_HEIGHT / 2. - c1_proj.y;
	draw_line(env, (t_coord2c){(int)c0_proj.x, (int)c0_proj.y, c0.z},
					(t_coord2c){(int)c1_proj.x, (int)c1_proj.y, c1.z},
					fcolor);
}

int				(*colf(t_env *env))(double)
{
	static int (*c_table[N_COLORS])(double) = {
		&color_terrain, &color_jet,
		&color_grayscale, &color_red, &color_green, &color_blue};

	return (c_table[env->color]);
}

void			clear_image(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			env->image[y * WIN_WIDTH + x] = 0;
			x++;
		}
		y++;
	}
}

void			draw_grid(t_env *env)
{
	int			x;
	int			y;
	t_coord3	c;

	clear_image(env);
	env->pm = make_projection(env->phi, env->theta);
	y = 0;
	while (y < env->dim.y)
	{
		x = 0;
		while (x < env->dim.x)
		{
			c = get_coord(env, x, y);
			if (x > 0)
				segment3d_altitude(env, c, get_coord(env, x - 1, y), colf(env));
			if (y > 0)
				segment3d_altitude(env, c, get_coord(env, x, y - 1), colf(env));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env, env->mlx_win, env->image_ptr, 0, 0);
}
