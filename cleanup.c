/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:54:27 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/09 14:54:28 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fdf.h"
#include "my_malloc.h"
#include "mlx.h"

void	cleanup(t_env *env)
{
	my_malloc_cleanup(&(env->allocated));
}

void	die(t_env *env)
{
	write(1, "Exiting gracefully.\n", 20);
	cleanup(env);
	if (env->mlx_win != NULL)
		mlx_destroy_window(env->mlx_ptr, env->mlx_win);
	exit(0);
}
