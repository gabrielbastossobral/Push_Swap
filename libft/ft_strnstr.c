/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:56:12 by gabastos          #+#    #+#             */
/*   Updated: 2024/10/15 09:56:15 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*src;
	const char	*find;
	size_t		i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		src = haystack;
		find = needle;
		while (find[i] && src[i] == find[i] && (i < len))
			i++;
		if (find[i] == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
