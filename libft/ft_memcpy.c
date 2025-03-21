/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:03:55 by gserafio          #+#    #+#             */
/*   Updated: 2025/03/19 21:41:59 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_unsigned;
	const unsigned char	*src_unsigned;
	unsigned int		i;

	i = 0;
	dest_unsigned = dest;
	src_unsigned = src;
	if (dest == (void *)0 && src == (void *)0)
		return ((void *)0);
	while (i < n)
	{
		dest_unsigned[i] = src_unsigned[i];
		i++;
	}
	return ((unsigned char *)(dest_unsigned));
}
