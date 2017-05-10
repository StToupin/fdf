/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 11:37:21 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/09 11:37:23 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_numbers(char *line)
{
	int i;
	int	pos;
	int	count;

	count = 0;
	pos = -1;
	i = 0;
	while (1)
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\0')
		{
			if (i - pos - 1 > 0)
				count++;
			pos = i;
		}
		if (line[i] == '\0')
			return (count);
		i++;
	}
	return (count);
}

void	read_numbers(char *line, int *tab)
{
	int i;
	int	pos;
	int	count;

	count = 0;
	pos = -1;
	i = 0;
	while (1)
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\0')
		{
			if (i - pos - 1 > 0)
				tab[count++] = ft_atoi(line + pos + 1);
			pos = i;
		}
		if (line[i] == '\0')
			return ;
		i++;
	}
}
