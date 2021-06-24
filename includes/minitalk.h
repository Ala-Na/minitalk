/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:29:36 by elanna            #+#    #+#             */
/*   Updated: 2021/06/24 21:07:34 by elanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

/*
** Utils functions
*/
int	ft_atoi(const char *nptr);
int	ft_isprintable(char *str);
int	ft_isnumber(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd); 

/*
** Functions used by server
*/
void	get_char_by_char(int last_bit_rec);
void	server_handler(int sig, siginfo_t *info, void *ucontext);

/*
** Functions used by client
*/
void	client_handler(int sig, siginfo_t *info, void *ucontext);
int		error_management(int kill_error);
int		send_char_as_bits(char c, pid_t server_pid);
int		send_str_as_bits(char *str, pid_t server_pid);

#endif
