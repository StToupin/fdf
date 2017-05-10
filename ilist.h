/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ilist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 11:48:39 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/10 11:50:32 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILIST_H
# define ILIST_H
# include "my_malloc.h"

typedef struct	s_ilist_elem
{
	size_t				len;
	int					*s;
	struct s_ilist_elem	*prev;
	struct s_ilist_elem	*next;
}				t_ilist_elem;

typedef struct	s_ilist
{
	t_ilist_elem	*first;
	t_ilist_elem	*last;
	size_t			len;
	size_t			total_len;
}				t_ilist;

void			ilist_create(t_ilist *ilist);
int				ilist_push_front(t_allocated **a_list,
									t_ilist *ilist, char *s, size_t len);
void			ilist_pop_back(t_allocated **a_list,
								t_ilist *ilist, int *dest, size_t *len);
int				**ilist_join(t_allocated **a_list, t_ilist *ilist);

#endif
