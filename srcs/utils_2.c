/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:03:48 by elanna            #+#    #+#             */
/*   Updated: 2021/06/24 21:03:58 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	return_value(long int res, long int sign)
{
	if (res < 0 && sign > 0)
		return (-1);
	else if (res < 0 && sign < 0)
		return (0);
	res *= sign;
	return ((int)res);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	nbr;
	long int		res;
	long int		sign;

	nbr = 0;
	res = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nbr = *nptr - '0';
		res = res * 10 + nbr;
		nptr++;
	}
	return ((int)return_value(res, sign));
}

