/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:34:46 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/03/18 13:36:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("\033[31mBad Request: Insert 3 args, eg: ./client <PID> <Message>...\033[31m\n");
        return (-1);
    }

    kill(atoi(argv[1]), SIGUSR1);
    return (0);
}