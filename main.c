/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:52:22 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/09 14:52:23 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_env	env;
	int		err;

	(void)argc;
	(void)argv;
	err = init(&env);
	if (err)
		write(1, "Error\n", 6);
	die(&env);
	return (0);
}
