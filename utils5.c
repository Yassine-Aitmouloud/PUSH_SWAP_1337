/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:16:29 by yaaitmou          #+#    #+#             */
/*   Updated: 2025/02/24 18:02:27 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

char	**ft_make(char const *s, char c, char **ptr, size_t len)
{
	size_t	y;
	size_t	i;

	y = 0;
	i = 0;
	while (y < len)
	{
		while (s[i] == c)
			i++;
		ptr[y] = ft_word(s, c, &i);
		if (ptr[y] == NULL)
		{
			ft_free(ptr);
			return (NULL);
		}
		y++;
	}
	ptr[y] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**ptr;

	if (!s)
		return (NULL);
	len = ft_count_word(s, c);
	ptr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!ptr)
		return (NULL);
	return (ft_make(s, c, ptr, len));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	lenmalloc;
	size_t	lenfors2;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	i = 0;
	lenfors2 = 0;
	lenmalloc = ft_strlen(s1) + ft_strlen(s2);
	string = malloc(sizeof(char) * (lenmalloc + 1));
	if (!string)
		return (NULL);
	while (i < lenmalloc && s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[lenfors2] != '\0' && i < lenmalloc)
		string[i++] = s2[lenfors2++];
	string[lenmalloc] = '\0';
	return (string);
}

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
