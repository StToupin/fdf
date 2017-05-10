/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 11:50:36 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/10 11:50:38 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_malloc.h"
#include "ilist.h"
#include "fdf.h"

void		ilist_create(t_ilist *ilist)
{
	ilist->len = 0;
	ilist->total_len = 0;
	ilist->first = NULL;
	ilist->last = NULL;
}

int			ilist_push_front(t_allocated **a_list,
								t_ilist *ilist, char *s, size_t len)
{
	t_ilist_elem	*element;

	element = (t_ilist_elem*)my_malloc(a_list, sizeof(t_ilist_elem)
									+ sizeof(int) * len);
	if (element == NULL)
		return (1);
	element->s = (void*)element + sizeof(t_ilist_elem);
	read_numbers(s, element->s);
	element->len = len;
	element->next = ilist->first;
	element->prev = NULL;
	if (ilist->len == 0)
		ilist->last = element;
	else
		ilist->first->prev = element;
	ilist->first = element;
	ilist->len++;
	ilist->total_len += len;
	return (0);
}

void		ilist_pop_back(t_allocated **a_list,
							t_ilist *ilist, int *dest, size_t *len)
{
	t_ilist_elem	*element;
	size_t			i;

	*len = 0;
	if (ilist->len == 0)
		return ;
	element = ilist->last;
	ilist->last = element->prev;
	if (ilist->len == 1)
		ilist->first = NULL;
	else
		ilist->last->next = NULL;
	ilist->len--;
	ilist->total_len -= element->len;
	*len = element->len;
	i = -1;
	while (++i < *len)
		dest[i] = element->s[i];
	my_malloc_free(a_list, element);
}

int			**ilist_join(t_allocated **a_list, t_ilist *ilist)
{
	int		**joined;
	size_t	elem_len;
	int		*ptr;
	int		**pptr;

	joined = (int**)my_malloc(a_list, sizeof(int*) * (ilist->len)
										+ sizeof(int) * (ilist->total_len));
	if (joined == NULL)
		return (NULL);
	pptr = joined;
	ptr = (int*)((void*)joined + sizeof(int*) * (ilist->len));
	while (ilist->len > 0)
	{
		ilist_pop_back(a_list, ilist, ptr, &elem_len);
		*pptr = ptr;
		ptr += elem_len;
		pptr++;
	}
	return (joined);
}
