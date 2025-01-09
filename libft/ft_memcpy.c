/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:46:30 by gabastos          #+#    #+#             */
/*   Updated: 2024/10/16 11:05:53 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*p;
	unsigned char	*b;

	if (!dest && !src)
		return (0);
	count = 0;
	p = (unsigned char *)src;
	b = (unsigned char *)dest;
	while (count < n)
	{
		b[count] = p[count];
		count++;
	}
	return (dest);
}
