/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:16:26 by yaaitmou          #+#    #+#             */
/*   Updated: 2025/02/24 18:26:20 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_dup(t_list *lst)
{
	t_list	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (if_the_same(lst->content, tmp->content) == 1)
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*tmp;

	if (lst == NULL || new_node == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
	}
	else
	{
		tmp = ft_lstlast(*lst);
		if (tmp)
			tmp->next = new_node;
	}
}

int	ft_atoi(const char *str, int *error)
{
	long int	res;

	int (i), (sign);
	if (!*str)
		return (0);
	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if ((sign == 1 && res > 2147483647)
			|| (sign == -1 && - res < -2147483648))
			return (*error = 1, 0);
		i++;
	}
	return (res * sign);
}

char	*ft_word(char const *s, char c, size_t *i)
{
	size_t	word;
	size_t	y;
	char	*ptr;

	word = 0;
	while (s[(*i)] && s[(*i)] != c)
	{
		word++;
		(*i)++;
	}
	*i = *i - word;
	y = 0;
	ptr = (char *)malloc(word + 1);
	if (!ptr)
		return (NULL);
	while (s[(*i)] && s[(*i)] != c)
	{
		ptr[y] = s[(*i)];
		(*i)++;
		y++;
	}
	ptr[y] = '\0';
	(*i)++;
	return (ptr);
}

size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}
