/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:52:31 by gabrielsobr       #+#    #+#             */
/*   Updated: 2025/01/07 17:30:28 by gabrielsobr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return (-1);
	tmp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
	return (0);
}

int	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra\n", 1);
	return (0);
}

int	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb\n", 1);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (rotate(stack_a) == -1 || rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rr\n", 1);
	return (0);
}
