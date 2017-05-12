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
	int dum[3];

	env->mlx_ptr = mlx_init();
	if (env->mlx_ptr == NULL)
		return (1);
	env->mlx_win = mlx_new_window(env->mlx_ptr, WIN_WIDTH,
									WIN_HEIGHT, "fdf");
	if (env->mlx_win == NULL)
		return (1);
	env->image_ptr = mlx_new_image(env->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (env->image_ptr == NULL)
		return (1);
	env->image = (int*)mlx_get_data_addr(env->image_ptr, dum, dum + 1, dum + 2);
	mlx_hook(env->mlx_win, 17, 0, &hook_close, env);
	mlx_hook(env->mlx_win, 2, 0, &hook_key, env);
	mlx_loop_hook(env->mlx_ptr, &hook_loop, env);
	mlx_expose_hook(env->mlx_win, &hook_expose, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}

int	init(t_env *env)
{
	env->mlx_ptr = NULL;
	env->mlx_win = NULL;
	env->image = NULL;
	env->image_ptr = NULL;
	env->theta = 45. * M_PI / 180.;
	env->phi = 30. * M_PI / 180.;
	env->autorotate = 0;
	env->scale = (t_coord3){30., 30., 30.};
	env->color = 0;
	my_malloc_init(&(env->allocated));
	return (0);
}
