/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:16:43 by yaaitmou          #+#    #+#             */
/*   Updated: 2025/02/24 17:09:10 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	write_error(char **string_form, t_list *stack_a)
{
	write(2, "Error\n", 6);
	ft_free(string_form);
	free_stack(stack_a);
	return (1);
}

void	rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*tmp;

	if (stack_a || *stack_a || (*stack_a)->next)
	{
		tmp = *stack_a;
		while (tmp->next->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
		write(1, "rra\n", 4);
	}
}

void	algo(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		sort_of_2(stack_a);
	else if (size == 3)
		sort_of_3(stack_a);
	else if (size <= 5)
		sort_of_5(stack_a, stack_b);
	else
		sort_algo(stack_a, stack_b, size);
}

int	find_min_position(t_list *stack)
{
	int		min;
	int		pos;
	int		i;
	t_list	*tmp;

	tmp = stack;
	min = tmp->content;
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (pos);
}
