/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 17:05:57 by elanna            #+#    #+#             */
/*   Updated: 2021/06/22 17:19:35 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_signal_received = 0;

void	client_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)info;
	(void)ucontext;
	g_signal_received = 1;
}

int	error_management(int kill_error)
{
	int	remaining_sec;

	remaining_sec = 0;
	if (kill_error != 0)
		return (1);
	while (!g_signal_received)
		remaining_sec = usleep(500);
	if (!g_signal_received && remaining_sec == 0)
		return (1);
	return (0);
}

int	send_char_as_bits(char c, pid_t server_pid)
{
	int					kill_error;
	int					bit;
	int					i;
	struct sigaction	act;

	i = 7;
	act.sa_sigaction = &client_handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) != 0)
		return (1);
	while (i >= 0)
	{
		g_signal_received = 0;
		bit = (c >> i--) & 1;
		if (bit == 1)
			kill_error = kill(server_pid, SIGUSR1);
		else
			kill_error = kill(server_pid, SIGUSR2);
		if (error_management(kill_error) == 1)
			return (1);
	}
	return (0);
}

int	send_str_as_bits(char *str, pid_t server_pid)
{
	int	i;
	int	error;

	i = 0;
	while (str[i])
	{
		error = send_char_as_bits(str[i], server_pid);
		i++;
		if (error == 1)
			break ;
	}
	if (error != 1)
		error = send_char_as_bits (0, server_pid);
	if (error == 1)
	{
		ft_putstr_fd("Error while sending message to server\n", 2);
		return (1);
	}
	ft_putstr_fd("Message received by server\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*str;

	if (argc != 3)
		ft_putstr_fd("Not enough or too much arguments !\n", 2);
	else
	{
		if (ft_isnumber(argv[1]) == 0)
		{
			ft_putstr_fd("First argument given is not a number !\n", 2);
			return (1);
		}
		else if (ft_isprintable(argv[2]) == 0)
		{
			ft_putstr_fd("Second argument is not a printable string !\n", 2);
			return (1);
		}
		server_pid = ft_atoi(argv[1]);
		str = argv[2];
		if (send_str_as_bits(str, server_pid) == 1)
			return (1);
	}
	return (0);
}
