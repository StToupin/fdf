/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 12:22:11 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/05 10:23:34 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "my_malloc.h"
#include "slist.h"
#include "get_next_line.h"

static t_openfile	*get_openfile(t_allocated **a_list,
									t_openfile **oflist, int fd)
{
	t_openfile	*elem;
	int			found;

	elem = *oflist;
	found = 0;
	while (elem != NULL && !found)
	{
		if (elem->fd == fd)
			found = 1;
		else
			elem = elem->next;
	}
	if (!found)
	{
		elem = (t_openfile*)my_malloc(a_list, sizeof(t_openfile));
		if (elem == NULL)
			return (NULL);
		elem->fd = fd;
		elem->first_call = 1;
		elem->next = *oflist;
		elem->buf_size = 0;
		elem->buf_pos = elem->buf;
		*oflist = elem;
	}
	return (elem);
}

static int			del_openfile(t_allocated **a_list,
									t_openfile **oflist, int fd)
{
	t_openfile *elem;
	t_openfile *prev;

	elem = *oflist;
	prev = NULL;
	while (elem->fd != fd)
	{
		prev = elem;
		elem = elem->next;
	}
	if (prev == NULL)
		*oflist = elem->next;
	else
		prev->next = elem->next;
	my_malloc_free(a_list, elem);
	return (0);
}

static int			expand_str(t_allocated **a_list,
								t_slist *slist, t_openfile *of)
{
	int		keep_on_reading;
	size_t	i;

	keep_on_reading = 1;
	i = 0;
	while (of->buf_pos + i < of->buf + of->buf_size && keep_on_reading)
	{
		if (of->buf_pos[i] == '\n')
			keep_on_reading = 0;
		else
			i++;
	}
	slist_push_front(a_list, slist, of->buf_pos, i);
	of->buf_pos += i + 1;
	return (keep_on_reading);
}

int					get_next_line(t_allocated **a_list,
									const int fd, char **line)
{
	static t_openfile	*oflist = NULL;
	t_openfile			*of;
	t_slist				slist;

	if (fd < 0 || line == NULL
		|| (of = get_openfile(a_list, &oflist, fd)) == NULL)
		return (-1);
	*line = NULL;
	if (of->eof == 1)
		return (del_openfile(a_list, &oflist, fd));
	slist_create(&slist);
	while (of->eof == 0 && expand_str(a_list, &slist, of))
	{
		if ((of->buf_size = read(fd, of->buf, BUFF_SIZE)) == -1)
			return (-1);
		of->buf_pos = of->buf;
		of->eof = (of->buf_size == 0);
	}
	if (slist.len == 0 && of->eof == 0)
		return (-1);
	if (of->eof && slist.len == 0)
		return (del_openfile(a_list, &oflist, fd));
	*line = slist_join(a_list, &slist);
	return (1);
}
