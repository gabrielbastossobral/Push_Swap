/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:01:31 by gabrielsobr       #+#    #+#             */
/*   Updated: 2025/01/07 17:30:55 by gabrielsobr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	t_list	*get_next_min(t_list **stack)
{
	t_list	*current;
	t_list	*min_node;

	current = *stack;
	min_node = NULL;
	while (current)
	{
		if (current->index == -1)
		{
			if (!min_node || current->value < min_node->value)
				min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}
