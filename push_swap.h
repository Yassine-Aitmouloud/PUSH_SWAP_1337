#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int	ft_atoi(const char *str);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new_node);
void				ft_lstadd_front(t_list **lst, t_list *new_node);
char	**ft_split(char const *s, char c);
char	**ft_make(char const *s, char c, char **ptr, size_t len);
void	ft_free(char **ptr);
size_t	ft_count_word(char const *s, char c);
char	*ft_word(char const *s, char c, size_t *i);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
