/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:01:54 by elanna            #+#    #+#             */
/*   Updated: 2021/06/24 21:03:29 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		i++;
	write(fd, s, i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	nb;

	if (n < 0)
	{
		c = '-';
		write(fd, &c, 1);
		nb = -n;
	}
	else
		nb = n;
	if (nb / 10 > 0)
		ft_putnbr_fd(nb / 10, fd);
	c = '0' + (nb % 10);
	write(fd, &c, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (2480);
}

int	ft_isprintable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] > '~')
			return (0);
		i++;
	}
	return (16384);
}
