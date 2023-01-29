/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:11:31 by mazaroua          #+#    #+#             */
/*   Updated: 2023/01/08 16:11:33 by mazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include "Libft/libft.h"

void	variables_assignement(char *to_print, int *i)
{
	*to_print = 0;
	*i = 0;
}

void	to_print_function(char *to_print, int *i)
{
	if (i == 0)
		*to_print = (*to_print << 0) | 1;
	else
		*to_print = (*to_print << 1) | 1;
}

void	signalhandler(int signal, siginfo_t *info, void *c)
{
	static int		i;
	static char		to_print;
	static pid_t	pid;

	(void)c;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		variables_assignement(&to_print, &i);
	}
	if (signal == SIGUSR1)
		to_print_function(&to_print, &i);
	else if (signal == SIGUSR2)
		to_print = to_print << 1;
	i++;
	if (i == 8)
	{
		if (to_print == 0)
			kill(pid, SIGUSR1);
		else
		{
			write(1, &to_print, 1);
			variables_assignement(&to_print, &i);
		}
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	pid = getpid();
	sig.sa_sigaction = &signalhandler;
	sig.sa_flags = SA_SIGINFO;
	write(1, "The Process ID: ", 16);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
}
