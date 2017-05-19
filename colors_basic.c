/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 12:19:57 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/19 10:15:48 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
