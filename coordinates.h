/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:23:42 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/09 14:23:44 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATES_H
# define COORDINATES_H

typedef struct	s_coord2
{
	double x;
	double y;
}				t_coord2;

typedef struct	s_coord2c
{
	int		x;
	int		y;
	double	c;
}				t_coord2c;

typedef struct	s_coord3
{
	double x;
	double y;
	double z;
}				t_coord3;

typedef struct	s_proj_matrix
{
	t_coord3 v0;
	t_coord3 v1;
}				t_proj_matrix;

t_proj_matrix	make_projection(double phi, double theta);
t_coord3		do_scale(t_coord3 c3, t_coord3 scale);
t_coord2		do_projection(t_proj_matrix *m, t_coord3 c3);

#endif
