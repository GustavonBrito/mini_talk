/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:34:41 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/03/18 13:15:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_sigusr1(int sig)
{
	write(1, "Sinal recebido\n", 15);
}

int main(void)
{
	int pid;

	pid = 0;
	pid = getpid();
	printf("\033[94mPID\033[0m \033[96m->\033[0m %d\n", pid);
	printf("\033[90mWaiting for a message...\033[0m\n");
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr1);
	while (1)
		pause();
	return (0);
}