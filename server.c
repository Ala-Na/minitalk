/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:41:06 by elanna            #+#    #+#             */
/*   Updated: 2021/06/21 23:27:59 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static void	handler(int sig, siginfo_t *info, void *ucontext)
{
	if (sig == SIGUSR1)
	{

	}
	else if (sig == SIGUSR2)
	{

	}
}

int	main()
{
	struct sigaction	act;
	pid_t	pid;

	pid = getpid();
	printf("%i\n", pid);
	act.sa_sigaction = &handler;
	act.sa_flags = SA_SIGINFO;
	while (1)
		pause();
	return (0);
}
