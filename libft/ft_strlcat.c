/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:30:48 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/03/19 21:42:46 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dest_size;
	unsigned int	src_size;

	i = 0;
	dest_size = 0;
	src_size = 0;
	src_size = ft_strlen(src);
	dest_size = ft_strlen(dst);
	if (size == 0)
		return (src_size);
	while (dest_size + i < size - 1 && src[i])
	{
		dst[dest_size + i] = src[i];
		i++;
	}
	dst[dest_size + i] = '\0';
	if (size <= dest_size)
		return (src_size + size);
	return (dest_size + src_size);
}
