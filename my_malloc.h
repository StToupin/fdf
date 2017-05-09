/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:59:10 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/09 13:59:13 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MALLOC_H
# define MY_MALLOC_H
# include <stdlib.h>

typedef struct	s_allocated
{
	void	*ptr;
	void	*next;
}				t_allocated;

void			my_malloc_init(t_allocated **a_list);
void			*my_malloc(t_allocated **a_list, size_t size);
void			my_malloc_cleanup(t_allocated **a_list);

#endif
