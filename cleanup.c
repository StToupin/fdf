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

int		die(t_env *env)
{
	int count;

	ft_putstr_fd("Exiting gracefully.\n", 1);
	count = my_malloc_cleanup(&(env->allocated));
	ft_putnbr_fd(count, 1);
	ft_putstr_fd(" pointer(s) were left allocated.\n", 1);
	if (env->mlx_win != NULL)
		mlx_destroy_window(env->mlx_ptr, env->mlx_win);
	exit(0);
}
