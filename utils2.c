/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:16:21 by yaaitmou          #+#    #+#             */
/*   Updated: 2025/02/23 19:06:29 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nodes(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_list **stack_a)
{
	if ((*stack_a)->next)
	{
		swap_nodes(stack_a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_list **stack_b)
{
	if ((*stack_b)->next)
	{
		swap_nodes(stack_b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_b)->next && (*stack_a)->next)
	{
		swap_nodes(stack_a);
		swap_nodes(stack_b);
		write(1, "ss\n", 3);
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b)
	{
		tmp = (*stack_b)->next;
		ft_lstadd_front(stack_a, *stack_b);
		*stack_b = tmp;
		write(1, "pa\n", 3);
	}
}
