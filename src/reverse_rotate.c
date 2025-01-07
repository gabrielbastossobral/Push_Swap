/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:26:15 by gabrielsobr       #+#    #+#             */
/*   Updated: 2025/01/07 12:37:29 by gabrielsobr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return (-1);
	tmp = *stack;
	last = *stack;
	while (last->next->next)
		last = last->next;
	*stack = last->next;
	last->next = NULL;
	(*stack)->next = tmp;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra\n", 1);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb\n", 1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (reverse_rotate(stack_a) == -1 || reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrr\n", 1);
	return (0);
}
