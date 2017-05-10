/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:43:17 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/09 14:43:19 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "my_malloc.h"
#include "mlx.h"

int	init_mlx(t_env *env)
{
	env->mlx_ptr = mlx_init();
	if (env->mlx_ptr == NULL)
		return (1);
	env->mlx_win = mlx_new_window(env->mlx_ptr, (int)env->win_dim.x,
									(int)env->win_dim.y, "fdf");
	if (env->mlx_win == NULL)
		return (1);
	mlx_hook(env->mlx_win, 17, 0, &hook_close, env);
	mlx_key_hook(env->mlx_win, &hook_key, env);
	draw_gizmo(env);
	mlx_loop(env->mlx_ptr);
	return (0);
}

int	init(t_env *env)
{
	env->win_dim = (t_coord2){640., 480.};
	env->mlx_ptr = NULL;
	env->mlx_win = NULL;
	env->theta = 45. * M_PI / 180.;
	env->phi = 30. * M_PI / 180.;
	env->scale = (t_coord3){50., 50., 50.};
	my_malloc_init(&(env->allocated));
	return (0);
}
