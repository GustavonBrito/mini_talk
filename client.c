/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:34:46 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/03/21 22:33:14 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/minitalk.h"

int		g_server_confirm = 0;

void	handle_info_sent(int pid)
{
	if (pid == SIGUSR1)
	{
		g_server_confirm = 1;
	}
}

void	post_datas(int pid, char *message)
{
	int	bit_per_bit;
	int	i;

	bit_per_bit = 7;
	i = 0;
	while (1)
	{
		bit_per_bit = 7;
		while (bit_per_bit >= 0)
		{
			if (message[i] >> bit_per_bit & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit_per_bit--;
			while (!g_server_confirm)
				;
			g_server_confirm = 0;
		}
		if (message[i] == '\0')
			break ;
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
	signal(SIGUSR1, handle_info_sent);
	post_datas(ft_atoi(argv[1]), argv[2]);
	return (0);
}
