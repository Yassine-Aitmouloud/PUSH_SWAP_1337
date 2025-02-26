/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:16:35 by yaaitmou          #+#    #+#             */
/*   Updated: 2025/02/21 22:18:10 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_position(t_list **stack_a, int size)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	while (tmp && i < size)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

void	sort_of_2(t_list **stack_a)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

int	*ft_sort_numbers(t_list **stack_a)
{
	int	size;
	int	*numbers;

	size = ft_lstsize(*stack_a);
	if (size == 0)
		return (NULL);
	numbers = ft_get_numbers(*stack_a, size);
	if (!numbers)
		return (NULL);
	sorting(numbers, size);
	return (numbers);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_a;
	t_list	*last_b;
	t_list	*tmp;

	if ((*stack_b || (*stack_b)->next) && (*stack_a || (*stack_a)->next))
	{
		tmp = *stack_a;
		while (tmp->next->next)
			tmp = tmp->next;
		last_a = tmp->next;
		tmp->next = NULL;
		last_a->next = *stack_a;
		*stack_a = last_a;
		tmp = *stack_b;
		while (tmp->next->next)
			tmp = tmp->next;
		last_b = tmp->next;
		tmp->next = NULL;
		last_b->next = *stack_b;
		*stack_b = last_b;
		write(1, "rrr\n", 4);
	}
}

void	rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*tmp;

	if (stack_b || *stack_b || (*stack_b)->next)
	{
		tmp = *stack_b;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = *stack_b;
		*stack_b = last;
		write(1, "rrb\n", 4);
	}
}
