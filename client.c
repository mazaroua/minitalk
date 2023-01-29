/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazaroua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:56:08 by mazaroua          #+#    #+#             */
/*   Updated: 2022/12/31 18:56:12 by mazaroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include "Libft/libft.h"

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

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			ft_send(pid, av[2][i]);
			i++;
		}
	}
	else
	{
		write(1, "\033[0;31m", 8);
		write(1, "Invalid Arguments", 18);
	}
}
