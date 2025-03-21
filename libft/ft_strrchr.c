/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:01:27 by marvin            #+#    #+#             */
/*   Updated: 2025/03/19 21:43:08 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

char	*ft_strrchr(char *s, int c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (c > 255)
		c = c % 256;
	while (s[i])
	{
		if (ft_isascii(s[i]) == 0)
			return (0);
		if (s[i] == c)
		{
			s = &s[i];
			i = 0;
			flag = 1;
		}
		i++;
	}
	if (flag == 1)
		return (s);
	if (c == 0)
		return (s = &s[i]);
	return (0);
}
