/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:05:57 by elanna            #+#    #+#             */
/*   Updated: 2021/06/21 21:48:48 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

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

int	ft_isnumber(char *str)
{
	int i;

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
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] > '~')
			return (0);
		i++;
	}
	return (16384);
}

void	ft_print_bin_rep(size_t const size, void const *ptr)
{
	unsigned char	*byte;
	unsigned char	bit;
	int				i;
	int				j;

	byte = (unsigned char *)ptr;
	i = size - 1;
	while (i >= 0)
	{
		j = 7;
		while (j >= 0)
		{
			bit = (byte[i] >> j) & 1;
			printf("%i", bit);
			j--;
		}
		printf(" ");
		i--;
	}
	printf("\n");
}

void	send_char_as_bit(char c, pid_t server_pid)
{
	int	bit;
	int	i;
	
	i = 7;
	ft_print_bin_rep(sizeof(c), &c);
	while (i >= 0)
	{
		bit = (c >> i--) & 1;
		if (bit == 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*str;

	if (argc != 3)
		printf("Not enough or too much arguments !\n");
	else
	{
		if (ft_isnumber(argv[1]) == 0)
		{
			printf("First argument given is not a number !\n");
			return (0);
		}
		else if (ft_isprintable(argv[2]) == 0)
		{
			printf("Second argument is not a printable string !\n");
			return (0);
		}
		server_pid = ft_atoi(argv[1]);
		str = argv[2];
		while (1)
			send_char_as_bit('c', server_pid);
	}
	return (0);
} 
