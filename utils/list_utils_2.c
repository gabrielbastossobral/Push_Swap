/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:43:39 by gabrielsobr       #+#    #+#             */
/*   Updated: 2025/01/07 17:44:15 by gabrielsobr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **stack, t_list *new)
{
	new->next = *stack;
	*stack = new;
}
