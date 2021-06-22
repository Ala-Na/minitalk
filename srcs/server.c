/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:41:06 by elanna            #+#    #+#             */
/*   Updated: 2021/06/22 16:46:12 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_error = 0;

void	get_char_by_char(int last_bit_rec)
{
	static char	act_bit_nbr = 0;
	static char	act_char = 0;

	if (act_bit_nbr == 0)
		act_char = 0;
	act_char |= (last_bit_rec << (7 - act_bit_nbr++));
	if (act_bit_nbr == 8)
	{
		if (act_char == 0)
			write(1, "\n", 1);
		else
			write(1, &act_char, 1);
		act_bit_nbr = 0;
	}
}

void	server_handler(int sig, siginfo_t *info, void *ucontext)
{
	int	kill_error;

	(void)(ucontext);
	if (sig == SIGUSR1)
		get_char_by_char(1);
	else if (sig == SIGUSR2)
		get_char_by_char(0);
	kill_error = kill(info->si_pid, SIGUSR1);
	if (kill_error != 0)
	{
		ft_putstr_fd("Couldn't send acknoledgment to client\n", 2);
		g_error = 1;
	}
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	pid = getpid();
	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	act.sa_sigaction = &server_handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) != 0
		|| sigaction(SIGUSR2, &act, NULL) != 0)
	{
		ft_putstr_fd("Error while handling signals\n", 2);
		return (1);
	}
	while (g_error == 0)
		pause();
	if (g_error == 1)
		return (1);
	return (0);
}
