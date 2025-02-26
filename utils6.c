/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:16:32 by yaaitmou          #+#    #+#             */
/*   Updated: 2025/02/24 18:30:23 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	check_if_number(char *string)
{
	int	i;

	i = 0;
	if (!string[i])
		return (1);
	while (string[i])
	{
		if (!(ft_isdigit(string[i]) || ((string[i] == '-' || string[i] == '+')
					&& (i == 0 || string[i - 1] == ' ') && ft_isdigit(string[i
							+ 1]))))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_index_stack(t_list **stack_a, int *numbers, int size)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->content == numbers[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

int	*ft_get_numbers(t_list *stack, int size)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof(int) * size);
	if (!numbers)
		return (NULL);
	i = 0;
	while (stack)
	{
		numbers[i++] = stack->content;
		stack = stack->next;
	}
	return (numbers);
}

void	sorting(int *numbers, int size)
{
	int (i), (j);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] > numbers[j])
				ft_swap(&numbers[i], &numbers[j]);
			j++;
		}
		i++;
	}
}
