/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:16:11 by yaaitmou          #+#    #+#             */
/*   Updated: 2025/02/24 18:26:46 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	transform(char *av, t_list **stack_a)
{
	char	**string_form;
	t_list	*node;

	int (j), (int_form), (error);
	error = 0;
	string_form = ft_split(av, ' ');
	if (!string_form || string_form[0] == NULL)
		return (write_error(string_form, *stack_a));
	j = 0;
	while (string_form[j])
	{
		if (check_if_number(string_form[j]))
			return (write_error(string_form, *stack_a));
		int_form = ft_atoi(string_form[j], &error);
		if (error)
			return (write_error(string_form, *stack_a));
		node = ft_lstnew(int_form);
		if (!node)
			return (write_error(string_form, *stack_a));
		ft_lstadd_back(stack_a, node);
		j++;
	}
	ft_free(string_form);
	return (0);
}

void	sort_of_4(t_list **stack_a, t_list **stack_b)
{
	int	pos;

	pos = find_min_position(*stack_a);
	if (pos == 1)
		sa(stack_a);
	else if (pos == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (pos == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_of_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_of_5(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
		move_smallest_to_b(stack_a, stack_b);
	sort_of_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_of_3(t_list **stack_a)
{
	int	biggest;

	biggest = find_biggest_value(*stack_a);
	if ((*stack_a)->content == biggest)
		ra(stack_a);
	if ((*stack_a)->next->content == biggest)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

int	main(int ac, char **av)
{
	int		size;
	int		*numbers;
	t_list	*stack_a;
	t_list	*stack_b;

	initialize_stacks(&stack_a, &stack_b);
	if (ac > 1)
	{
		if (handle_arguments(ac, av, &stack_a))
			return (1);
		if (if_dup(stack_a))
			return (write(2, "Error\n", 6), free_stack(stack_a), 1);
		if (is_sorted(stack_a))
			return (free_stack(stack_a), 0);
		size = ft_lstsize(stack_a);
		numbers = ft_sort_numbers(&stack_a);
		ft_index_stack(&stack_a, numbers, size);
		algo(&stack_a, &stack_b, size);
		free_stack(stack_a);
		free(numbers);
	}
	return (0);
}
