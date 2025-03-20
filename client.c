/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:34:46 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/03/20 01:23:46 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/minitalk.h"

void	post_datas(int pid, char *message)
{
	int	bit_per_bit;
	int	i;

	bit_per_bit = 7;
	i = 0;
	while (message[i])
	{
		bit_per_bit = 7;
		while (bit_per_bit >= 0)
		{
			if (message[i] >> bit_per_bit & 1)
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			bit_per_bit--;
			usleep(100);
		}
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("\033[31mInsert 3 args: ./client <PID> <Message>\033[31m\n");
		return (-1);
	}
	post_datas(ft_atoi(argv[1]), argv[2]);
	return (0);
}
