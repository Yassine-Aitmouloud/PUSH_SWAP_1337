/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaitmou <yaaitmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:16:15 by yaaitmou          #+#    #+#             */
/*   Updated: 2025/02/24 18:30:01 by yaaitmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				position;
	int				index;
	int				content;
	int				above_line;
	struct s_list	*next;
}					t_list;
void				move_smallest_to_b(t_list **stack_a, t_list **stack_b);
int					find_biggest_value(t_list *stack);
t_list				*find_smallest_node(t_list *stack);
int					transform(char *av, t_list **stack_a);
int					find_min_position(t_list *stack);
void				initialize_stacks(t_list **stack_a, t_list **stack_b);
int					handle_arguments(int ac, char **av, t_list **stack_a);
void				algo(t_list **stack_a, t_list **stack_b, int size);
int					is_sorted(t_list *stack_a);
int					if_the_same(int c, int d);
void				free_stack(t_list *stack);
void				move_big_index(t_list **stack_b);
int					*ft_get_numbers(t_list *stack, int size);
void				sort_algo(t_list **stack_a, t_list **stack_b, int size);
void				sort_of_5(t_list **stack_a, t_list **stack_b);
void				sort_of_4(t_list **stack_a, t_list **stack_b);
void				sort_of_3(t_list **stack_a);
void				sort_of_2(t_list **stack_a);
int					*ft_sort_numbers(t_list **stack_a);
void				ft_position(t_list **stack_a, int size);
void				ft_index_stack(t_list **stack_a, int *numbers, int size);
void				ft_swap(int *a, int *b);
void				sorting(int *numbers, int size);
int					write_error(char **string_form, t_list *stack_a);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				sb(t_list **lst);
void				sa(t_list **lst);
void				free_stack(t_list *stack);
int					check_if_number(char *string);
int					if_dup(t_list *lst);
int					ft_isprint(int c);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str, int *error);
t_list				*ft_lstnew(int content);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new_node);
void				ft_lstadd_front(t_list **lst, t_list *new_node);
char				**ft_split(char const *s, char c);
char				**ft_make(char const *s, char c, char **ptr, size_t len);
void				ft_free(char **ptr);
size_t				ft_count_word(char const *s, char c);
char				*ft_word(char const *s, char c, size_t *i);
char				*ft_strjoin(char const *s1, char const *s2);

#endif
