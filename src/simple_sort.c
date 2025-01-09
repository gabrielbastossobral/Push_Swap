/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:43:41 by gabrielsobr       #+#    #+#             */
/*   Updated: 2025/01/09 13:40:47 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min_index(t_list *stack)
{
	int	min;

	if (!stack)
		return (-1);
	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

void	bring_index_to_top(t_list **stack, int index)
{
	int		size;
	int		position;
	t_list	*current;

	size = ft_lstsize(*stack);
	position = 0;
	current = *stack;
	while (current && current->index != index)
	{
		position++;
		current = current->next;
	}
	if (position <= size / 2)
		while (position-- > 0)
			ra(stack);
	else
	{
		position = size - position;
		while (position-- > 0)
			rra(stack);
	}
}

void	sort_3(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (ft_lstsize(*stack_a) != 3)
		return ;
	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		rra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	min_index;

	min_index = find_min_index(*stack_a);
	bring_index_to_top(stack_a, min_index);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	min_index;

	min_index = find_min_index(*stack_a);
	bring_index_to_top(stack_a, min_index);
	pb(stack_a, stack_b);
	min_index = find_min_index(*stack_a);
	bring_index_to_top(stack_a, min_index);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
