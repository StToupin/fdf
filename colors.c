/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:46:22 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/10 10:46:23 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinates.h"

/*
** These functions associate a color to a number between 0. and 1.
*/

int	color_jet(double x)
{
	t_coord3	rgb;
	int			irgb;

	if (x < .25)
		rgb = (t_coord3){0., 4. * x, 1.};
	else if (x < .5)
		rgb = (t_coord3){0., 1., 1. + 4. * (.25 - x)};
	else if (x < .75)
		rgb = (t_coord3){4. * (x + .5), 1., 0.};
	else
		rgb = (t_coord3){1., 1. + 4. * (.75 - x), 0.};
	irgb = ((int)(255. * rgb.x) << 16)
			+ ((int)(255. * rgb.y) << 8)
			+ (int)(255. * rgb.z);
	return (irgb);
}

int	color_grayscale(double x)
{
	int rgb;

	rgb = (int)(x * 255);
	rgb = (rgb << 16) + (rgb << 8) + rgb;
	return (rgb);
}

int	color_red(double x)
{
	int rgb;

	rgb = (int)(x * 255);
	rgb <<= 16;
	return (rgb);
}

int	color_green(double x)
{
	int rgb;

	rgb = (int)(x * 255);
	rgb <<= 8;
	return (rgb);
}

int	color_blue(double x)
{
	int rgb;

	rgb = (int)(x * 255);
	rgb += ((rgb / 2) << 8) + ((rgb / 2) << 16);
	return (rgb);
}
