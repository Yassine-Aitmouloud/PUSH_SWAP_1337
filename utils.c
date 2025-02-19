#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t i;
	i = 0;
	while(str[i])
		i++;
	return(i);
}

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		counter++;
	}
	return (counter);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (lst && new_node)
	{
		new_node->next = *lst;
		*lst = new_node;
	}
}
int	if_dup(t_list *lst)
{
	t_list *tmp;
	while (lst != NULL)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (if_the_same(lst->content,tmp->content) == 1)
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

int	ft_atoi(const char *str,int *error)
{
	int	sign;
	long int	res;
	int	i;

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
		if ((sign == 1 && res > 2147483647) || (sign == -1 && -res < -2147483648))
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
		if (ft_isprint(s[i]))
			count++;
		while (ft_isprint(s[i]) && s[i] != c)
			i++;
	}
	return (count);
}

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
	return ( c >= 32 && c <= 126);
}
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	check_if_number(char *string)
{
	int i;
	i = 0;
	while(string[i])
	{
		if (!((ft_isdigit(string[i])) || (string[i] == '-' && ft_isdigit(string[i + 1])) || (string[i] == '+' && ft_isdigit(string[i + 1]))))
			return(1);
		i++;
	}
	return(0);
}
void free_stack(t_list *stack)
{
    t_list *tmp;
    
    while (stack)
    {
        tmp = stack->next;
        free(stack);
        stack = tmp;
    }
}
int	if_the_same(int c, int d)
{
	return(c == d);
}