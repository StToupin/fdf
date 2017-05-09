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

static void	segment3d(t_env *env, t_coord3 c0, t_coord3 c1, int color)
{
	t_coord2 c0_proj;
	t_coord2 c1_proj;

	do_scale(&c0, env->scale);
	do_scale(&c1, env->scale);
	c0_proj = do_projection(&(env->pm), c0);
	c1_proj = do_projection(&(env->pm), c1);
	c0_proj.x += env->win_dim.x / 2.;
	c0_proj.y = env->win_dim.y / 2. - c0_proj.y;
	c1_proj.x += env->win_dim.x / 2.;
	c1_proj.y = env->win_dim.y / 2. - c1_proj.y;
	draw_line(env, c0_proj, c1_proj, color);
}

void		draw(t_env *env)
{
	static t_coord3 o = {0., 0., 0.};
	static t_coord3 ux = {1., 0., 0.};
	static t_coord3 uy = {0., 1., 0.};
	static t_coord3 uz = {0., 0., 1.};

	env->pm = make_projection(env->phi, env->theta);
	mlx_clear_window(env->mlx_ptr, env->mlx_win);
	segment3d(env, o, ux, 0xff0000);
	segment3d(env, o, uy, 0x00ff00);
	segment3d(env, o, uz, 0x0000ff);
}
