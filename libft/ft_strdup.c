/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 00:51:17 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/03/19 21:42:38 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

char	*ft_strdup(const char *s)
{
	int		index;
	char	*string_dup;
	int		s_size;

	index = 0;
	s_size = 0;
	while (s[index])
	{
		index++;
		s_size++;
	}
	string_dup = (char *)malloc(s_size + 1 * sizeof(char));
	if (string_dup == (void *)0)
		return ((void *)0);
	index = 0;
	while (s[index])
	{
		string_dup[index] = s[index];
		index++;
	}
	string_dup[s_size] = '\0';
	return (string_dup);
}
