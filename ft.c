/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:50:23 by stoupin           #+#    #+#             */
/*   Updated: 2017/03/08 11:07:20 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_putstr_fd(char *str, int fd)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	write(fd, str, len);
	return (1);
}

static void	print_digit(int n, int fd)
{
	char digit;

	if (n == 0)
		return ;
	print_digit(n / 10, fd);
	if (n >= 0)
		digit = ('0' + (n % 10));
	else
		digit = ('0' - (n % 10));
	write(fd, &digit, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
		write(fd, "0", 1);
	else
		print_digit(n, fd);
}


static int	is_forbidden(char c)
{
	if (c <= 8)
		return (1);
	if (c >= 14 && c <= 31)
		return (1);
	if (c >= 33 && c <= 47)
		return (1);
	if (c >= 58)
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int number;
	int sign;

	number = 0;
	while ((*str < '0' || *str > '9') && *str != '-' && *str != '+')
	{
		if (is_forbidden(*str))
			return (0);
		str++;
	}
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0') * sign;
		str++;
	}
	return (number);
}
