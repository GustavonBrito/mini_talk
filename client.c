/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:34:46 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/03/18 18:18:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

void post_datas(int pid, char *message)
{
    int bit_per_bit;
    int i;

    bit_per_bit = 7;
    i = 0;
    while (message[i])
    {
        bit_per_bit = 7;
        while(bit_per_bit >= 0)
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
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("\033[31mBad Request: Insert 3 args, eg: ./client <PID> <Message>...\033[31m\n");
        return (-1);
    }

    post_datas(atoi(argv[1]), argv[2]);
    return (0);
}