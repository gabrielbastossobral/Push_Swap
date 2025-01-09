/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:48:32 by gabrielsobr       #+#    #+#             */
/*   Updated: 2025/01/09 13:57:00 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

int			swap(t_list **stack);
int			sa(t_list **stack_a);
int			sb(t_list **stack_b);
int			ss(t_list **stack_a, t_list **stack_b);

int			push(t_list **dst, t_list **src);
int			pa(t_list **stack_a, t_list **stack_b);
int			pb(t_list **stack_a, t_list **stack_b);

int			rotate(t_list **stack);
int			ra(t_list **stack_a);
int			rb(t_list **stack_b);
int			rr(t_list **stack_a, t_list **stack_b);

int			reverse_rotate(t_list **stack);
int			rra(t_list **stack_a);
int			rrb(t_list **stack_b);
int			rrr(t_list **stack_a, t_list **stack_b);

int			get_max(t_list *stack);
int			get_max_bits(int max);
void		radix_sort(t_list **stack_a, t_list **stack_b);

int			find_min_index(t_list *stack);
void		bring_index_to_top(t_list **stack, int index);
void		sort_3(t_list **stack_a);
void		sort_4(t_list **stack_a, t_list **stack_b);
void		sort_5(t_list **stack_a, t_list **stack_b);
void		simple_sort(t_list **stack_a, t_list **stack_b);

void		index_stack(t_list **stack);

t_list		*ft_new_node(int value, int index);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
void		ft_print_list(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstnew(int value);

void		ft_error(char *msg);
void		ft_free(char **str);
int			is_sorted(t_list **stack);
void		free_stack(t_list **stack);
int			get_distance(t_list **stack, int index);
void		make_top(t_list **stack, int distance);

void		ft_check_args(int argc, char **argv);

#endif