/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:11:23 by mazaroua          #+#    #+#             */
/*   Updated: 2023/01/08 16:11:25 by mazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include "Libft/libft.h"

void	handler(int signal)
{
	if (signal == SIGUSR1)
	{
		write(1, "\033[32m", 6);
		write(1, "Received", 8);
	}
}

void	ft_send(int pid, char data)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = (data << i) & 128;
		if (bit == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(300);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	signal(SIGUSR1, &handler);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			ft_send(pid, av[2][i]);
			i++;
		}
		ft_send(pid, '\0');
	}
	else
	{
		write(1, "\033[0;31m", 8);
		write(1, "Invalid Arguments", 18);
	}
}
