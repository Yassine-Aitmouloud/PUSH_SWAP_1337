#include "push_swap.h"
void swap_nodes(t_list **stack)
{
    if (!stack || !*stack || !(*stack)->next)
        return;

    t_list *first = *stack;
    t_list *second = (*stack)->next;

    first->next = second->next;
    second->next = first;
    *stack = second;
}

void sa(t_list **stack_a)
{
    swap_nodes(stack_a);
    write(1, "sa\n", 3);
}

void sb(t_list **stack_b)
{
    swap_nodes(stack_b);
    write(1, "sb\n", 3);
}

void ss(t_list **stack_a, t_list **stack_b)
{
    swap_nodes(stack_a);
    swap_nodes(stack_b);
    write(1, "ss\n", 3);
}
void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

    if (*stack_b)
    {
        tmp = (*stack_b)->next;
        ft_lstadd_front(stack_a, *stack_b);
        *stack_b = tmp;
        write(1, "pa\n", 3);
    }
}

void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *tmp;

    if (*stack_a)
    {
        tmp = (*stack_a)->next;
        ft_lstadd_front(stack_b, *stack_a);
        *stack_a = tmp;
        write(1, "pb\n", 3);
    }
}
void rotate(t_list **stack)
{
    if (!stack || !*stack || !(*stack)->next)
        return;

    t_list *first = *stack;
    t_list *last = *stack;

    while (last->next)
        last = last->next;

    *stack = first->next;
    first->next = NULL; 
    last->next = first;  
}

void ra(t_list **stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}

void rb(t_list **stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 3);
}

void rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
}
