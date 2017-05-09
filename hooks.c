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

int		hook_close(t_env *env)
{
	die(env);
	return (0);
}

int		hook_key(int key, t_env *env)
{
	(void)env;

	if (key == KEY_ESC)
		die(env);
	if (key == KEY_UP)
		env->theta += 10. * M_PI / 180.;
	if (key == KEY_DOWN)
		env->theta -= 10. * M_PI / 180.;
	if (key == KEY_LEFT)
		env->phi -= 10. * M_PI / 180.;
	if (key == KEY_RIGHT)
		env->phi -= 10. * M_PI / 180.;
	draw(env);
	return (0);
}
