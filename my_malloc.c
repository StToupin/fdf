/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:04:12 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/09 12:04:38 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "my_malloc.h"

void	my_malloc_init(t_allocated **a_list)
{
	*a_list = NULL;
}

void	*my_malloc(t_allocated **a_list, size_t size)
{
	void		*ptr;
	t_allocated	*elem;

	ptr = malloc(size + sizeof(t_allocated));
	if (ptr == NULL)
		return (NULL);
	elem = (t_allocated*)ptr;
	elem->ptr = ptr + sizeof(t_allocated);
	elem->next = *a_list;
	*a_list = elem;
	return (elem->ptr);
}

void	my_malloc_free(t_allocated **a_list, void *ptr)
{
	t_allocated *elem;
	t_allocated *prev;

	prev = NULL;
	elem = *a_list;
	while (elem != NULL)
	{
		if (elem->ptr == ptr)
		{
			if (prev == NULL)
				*a_list = elem->next;
			else
				prev->next = elem->next;
			free(elem);
			break ;
		}
		prev = elem;
		elem = elem->next;
	}
}

void	my_malloc_cleanup(t_allocated **a_list)
{
	t_allocated *elem;
	t_allocated *next;

	elem = *a_list;
	while (elem != NULL)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
}
