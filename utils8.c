/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:16:38 by yaaitmou          #+#    #+#             */
/*   Updated: 2025/02/21 22:17:45 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a)
	{
		tmp = (*stack_a)->next;
		ft_lstadd_front(stack_b, *stack_a);
		*stack_a = tmp;
		write(1, "pb\n", 3);
	}
}

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_list **stack_a)
{
	if ((*stack_a)->next)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **stack_b)
{
	if ((*stack_b)->next)
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->next && (*stack_b)->next)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
}
