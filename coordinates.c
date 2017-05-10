/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:23:48 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/09 14:23:50 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "coordinates.h"

t_proj_matrix	make_projection(double phi, double theta)
{
	double			c_phi;
	double			s_phi;
	double			c_theta;
	double			s_theta;
	t_proj_matrix	m;

	c_phi = cos(phi);
	s_phi = sin(phi);
	c_theta = cos(theta);
	s_theta = sin(theta);
	m.v0 = (t_coord3){c_phi, -s_phi, 0.};
	m.v1 = (t_coord3){s_phi * c_theta, c_phi * c_theta, s_theta};
	return (m);
}

double			dot_product3(t_coord3 v0, t_coord3 v1)
{
	return (v0.x * v1.x + v0.y * v1.y + v0.z * v1.z);
}

t_coord3		do_scale(t_coord3 c3, t_coord3 scale)
{
	return ((t_coord3){c3.x * scale.x, c3.y * scale.y, c3.z * scale.z});
}

t_coord2		do_projection(t_proj_matrix *m, t_coord3 c3)
{
	t_coord2 c2;

	c2.x = dot_product3(m->v0, c3);
	c2.y = dot_product3(m->v1, c3);
	return (c2);
}
