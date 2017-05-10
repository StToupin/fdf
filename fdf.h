/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:43:57 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/09 14:43:59 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "my_malloc.h"
# include "coordinates.h"

typedef	enum	e_key
{
	KEY_ESC = 53,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124
}				t_key;

typedef struct	s_env
{
	t_allocated		*allocated;
	t_coord2		dim;
	int				**map;
	void			*mlx_ptr;
	void			*mlx_win;
	t_coord2		win_dim;
	double			phi;
	double			theta;
	t_coord3		scale;
	t_proj_matrix	pm;
}				t_env;

int				init(t_env *env);
int				init_mlx(t_env *env);
int				die(t_env *env);

int				ft_putstr_fd(char *str, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_atoi(const char *str);

int				count_numbers(char *line);
void			read_numbers(char *line, int *tab);
int				load_file(t_env *env, int fd);

int				hook_close(t_env *env);
int				hook_key(int key, t_env *env);

int				draw_line(t_env *env, t_coord2c c0, t_coord2c c1,
							int (*fcolor)(double));

void			draw_gizmo(t_env *env);

#endif
