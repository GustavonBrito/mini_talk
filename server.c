/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:34:41 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/03/21 02:02:01 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	int				i;
	unsigned char	g = 0;
	static int		bit_count = 0;
	static char		byte_to_print[8];
	(void) context;
	
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
		if (g == 0)
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
		else
		{
			write(1, &g, 1);
			g = 0;
		}
		bit_count = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction sa;
	int	pid;

	pid = 0;
	pid = getpid();
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
	ft_printf("\033[90mWaiting for a message...\033[0m\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
