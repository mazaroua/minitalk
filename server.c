/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:00:35 by mazaroua          #+#    #+#             */
/*   Updated: 2022/12/31 19:00:38 by mazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include "Libft/libft.h"

void	variables_assignement(char *to_print, int *i)
{
	*to_print = 0;
	*i = 0;
}

void	signalhandler(int signal)
{
	static int		i;
	static char		to_print;

	if (signal == SIGUSR1)
	{
		if (i == 0)
			to_print = (to_print << 0) | 1;
		else
			to_print = (to_print << 1) | 1;
	}
	else if (signal == SIGUSR2)
		to_print = to_print << 1;
	i++;
	if (i == 8)
	{
		write(1, &to_print, 1);
		variables_assignement(&to_print, &i);
	}
}

int	main(void)
{
	pid_t				pid;

	pid = getpid();
	write(1, "The Process ID: ", 16);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, &signalhandler);
		signal(SIGUSR2, &signalhandler);
		pause();
	}
}
