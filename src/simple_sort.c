/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrielsobral <gabrielsobral@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:43:41 by gabrielsobr       #+#    #+#             */
/*   Updated: 2025/01/10 13:04:05 by gabrielsobr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

static void	execute_sort_case(t_list **stack_a, int case_id, int min)
{
	if (case_id == 1)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (case_id == 2)
	{
		if ((*stack_a)->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else if (case_id == 3)
	{
		if ((*stack_a)->next->index == min)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	sort_3(t_list **stack_a)
{
	int	min;
	int	next_min;
	int	case_id;

	if (is_sorted(stack_a))
		return ;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	case_id = 0;
	if ((*stack_a)->index == min && (*stack_a)->next->index != next_min)
		case_id = 1;
	else if ((*stack_a)->index == next_min)
		case_id = 2;
	else
		case_id = 3;
	execute_sort_case(stack_a, case_id, min);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
