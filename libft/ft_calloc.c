/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:32:40 by marvin            #+#    #+#             */
/*   Updated: 2024/10/24 10:45:40 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*memory;
	char	*ptr;
	size_t	i;

	if (num != 0 && size > SIZE_MAX / num)
		return (NULL);
	memory = malloc(num * size);
	ptr = (char *)memory;
	i = 0;
	if (!memory)
		return (NULL);
	while (i < num * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (memory);
}
