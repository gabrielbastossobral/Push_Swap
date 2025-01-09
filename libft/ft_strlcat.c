/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:46:09 by gabastos          #+#    #+#             */
/*   Updated: 2024/10/15 09:54:36 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	k;
	size_t	max;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize <= dlen)
		return (dstsize + slen);
	k = 0;
	max = dstsize - dlen - 1;
	while (k < max && src[k] != '\0')
	{
		dst[dlen + k] = src[k];
		k++;
	}
	dst[dlen + k] = '\0';
	return (dlen + slen);
}
