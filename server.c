/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:34:41 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/03/19 23:12:04 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/minitalk.h"

void	handle_signal(int sig)
{
	int				i;
	unsigned char	g;
	static int		bit_count = 0;
	static char		byte_to_print[8];

	if (sig == 10)
		byte_to_print[bit_count] = '1';
	else
		byte_to_print[bit_count] = '0';
	bit_count++;
	if (bit_count == 8)
	{
		byte_to_print[bit_count] = '\0';
		i = 0;
		while (i < 8)
		{
			g = (g << 1) | (byte_to_print[i] - '0');
			i++;
		}
		write(1, &g, 1);
		bit_count = 0;
		g = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = 0;
	pid = getpid();
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	write(1, "\n", 1);
	return (0);
}
