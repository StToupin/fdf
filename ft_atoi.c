/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stoupin <stoupin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:50:23 by stoupin           #+#    #+#             */
/*   Updated: 2017/03/08 11:07:20 by stoupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
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
	while (ft_isdigit(*str))
	{
		if (*str >= '0' && *str <= '9')
			number = number * 10 + (*str - '0') * sign;
		str++;
	}
	return (number);
}
