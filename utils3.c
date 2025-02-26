/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:16:24 by yaaitmou          #+#    #+#             */
/*   Updated: 2025/02/23 21:25:07 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algo(t_list **stack_a, t_list **stack_b, int size)
{
	int	helper;

	if (size < 130)
		helper = 15;
	else
		helper = 39;
	while (*stack_a)
	{
		if ((*stack_a)->index < ft_lstsize(*stack_b))
			pb(stack_a, stack_b);
		else if ((*stack_a)->index < ft_lstsize(*stack_b) + helper)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		else
			ra(stack_a);
	}
	while (*stack_b)
	{
		ft_position(stack_b, ft_lstsize(*stack_b));
		move_big_index(stack_b);
		pa(stack_a, stack_b);
	}
}

void	move_big_index(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*big_index;
	int		half;

	if (!*stack_b)
		return ;
	tmp = *stack_b;
	big_index = tmp;
	while (tmp)
	{
		if (tmp->index > big_index->index)
			big_index = tmp;
		tmp = tmp->next;
	}
	half = ft_lstsize(*stack_b) / 2;
	while (*stack_b != big_index)
	{
		if (big_index->position < half)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	if_the_same(int c, int d)
{
	return (c == d);
}

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
