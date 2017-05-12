/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:29:03 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/09 15:29:04 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "mlx.h"
#include "colors.h"

int			hook_close(t_env *env)
{
	die(env);
	return (0);
}

static void	rotate(t_env *env, int key)
{
	if (key == KEY_UP)
		env->theta += 5. * M_PI / 180.;
	if (key == KEY_DOWN)
		env->theta -= 5. * M_PI / 180.;
	if (key == KEY_LEFT)
		env->phi -= 5. * M_PI / 180.;
	if (key == KEY_RIGHT)
		env->phi += 5. * M_PI / 180.;
}

int			hook_key(int key, t_env *env)
{
	if (key == KEY_ESC)
		die(env);
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		rotate(env, key);
	if (key == KEY_PLUS)
		env->scale = (t_coord3){.9 * env->scale.x,
								.9 * env->scale.y,
								.9 * env->scale.z};
	if (key == KEY_MINUS)
		env->scale = (t_coord3){1.1 * env->scale.x,
								1.1 * env->scale.y,
								1.1 * env->scale.z};
	if (key == KEY_PAGEUP)
		env->scale = (t_coord3){env->scale.x, env->scale.y, 1.1 * env->scale.z};
	if (key == KEY_PAGEDOWN)
		env->scale = (t_coord3){env->scale.x, env->scale.y, .9 * env->scale.z};
	if (key == KEY_SPACE)
		env->color = (env->color + 1) % N_COLORS;
	if (key == KEY_ENTER)
		env->autorotate = 1 - env->autorotate;
	return (0);
}

int			hook_loop(t_env *env)
{
	if (env->autorotate)
		env->phi -= .5 * M_PI / 180.;
	draw_grid(env);
	return (0);
}

int			hook_expose(t_env *env)
{
	draw_grid(env);
	return (0);
}
