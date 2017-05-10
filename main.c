/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 14:52:22 by stoupin           #+#    #+#             */
/*   Updated: 2017/05/09 14:52:23 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "fdf.h"

static int	ft_putstr(char *str, int fd)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	write(fd, str, len);
	return (1);
}

static int	usage(char *exec)
{
	ft_putstr("Usage: ", 1);
	ft_putstr(exec, 1);
	ft_putstr(" file.fdf\n", 1);
	return (1);
}

static int	error_opening(char *filename)
{
	ft_putstr("Error opening '", 2);
	ft_putstr(filename, 2);
	ft_putstr("'.\n", 2);
	return (1);
}

int			main(int argc, char **argv)
{
	t_env	env;
	int		err;
	int		fd;

	if (argc != 2)
		return (usage(argv[0]));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error_opening(argv[1]));
	init(&env);
	err = load_file(&env, fd);
	close(fd);
	if (err)
		return (ft_putstr("Error while loading the file.\n", 2) & die(&env));
	err = init_mlx(&env);
	if (err)
		return (ft_putstr("Error while displaying the data.\n", 2) & die(&env));
	die(&env);
	return (0);
}
