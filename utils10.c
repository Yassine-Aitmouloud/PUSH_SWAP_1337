/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:39:58 by yaaitmou          #+#    #+#             */
/*   Updated: 2025/02/23 23:28:32 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_arguments(int ac, char **av, t_list **stack_a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (transform(av[i], stack_a))
			return (1);
		i++;
	}
	return (0);
}

void	initialize_stacks(t_list **stack_a, t_list **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
}

t_list	*find_smallest_node(t_list *stack)
{
	t_list	*tmp;
	t_list	*smallest;

	tmp = stack;
	smallest = tmp;
	ft_position(&stack, ft_lstsize(stack));
	while (tmp)
	{
		if (tmp->content < smallest->content)
			smallest = tmp;
		tmp = tmp->next;
	}
	return (smallest);
}

int	find_biggest_value(t_list *stack)
{
	t_list	*tmp;
	int		biggest;

	tmp = stack;
	biggest = tmp->content;
	while (tmp)
	{
		if (tmp->content > biggest)
			biggest = tmp->content;
		tmp = tmp->next;
	}
	return (biggest);
}

void	move_smallest_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest;

	smallest = find_smallest_node(*stack_a);
	while (*stack_a != smallest)
	{
		ft_position(stack_a, ft_lstsize(*stack_a));
		if (smallest->position < ft_lstsize(*stack_a) / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}
