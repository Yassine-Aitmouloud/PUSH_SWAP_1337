#include "push_swap.h"

int main(int ac, char **av)
{
    if (ac > 1)
    {
        int i;
        int check;
        char **string_form;
        int j;
        int int_form;
        t_list *node;
        t_list *stack_a;        
        stack_a = NULL;
        i = 1;
        while (i < ac)
        {
            string_form = ft_split(av[i], ' ');
            if (!string_form)
                return (1);
            if (string_form[0] == NULL)
            {
                ft_free(string_form);
                free_stack(stack_a);
                write(1,"Error\n",6);
                return(1);
            }
            j = 0;
            while (string_form[j])
            {
                check = check_if_number(string_form[j]);
                if (check)
                {
                    write(1,"Error\n",6);
                    ft_free(string_form);
                    free_stack(stack_a);
                    return (1);
                }
                int_form = ft_atoi(string_form[j]);
                node = ft_lstnew(int_form);
                if (!node)
                {
                    write(1,"Error\n",6);
                    ft_free(string_form);
                    free_stack(stack_a);
                    return(1);
                }
                ft_lstadd_back(&stack_a, node);
                j++;
            }
            ft_free(string_form);
            i++;
        }
        if(if_dup(stack_a))
        {
            write(1,"Error\n",6);
            return(1);
        }
        t_list *tmp = stack_a;
    while(tmp)
    {
        printf("%d\n", tmp->content);
        tmp = tmp->next;
    }   
    free_stack(stack_a);
    }
    return (0);
}
