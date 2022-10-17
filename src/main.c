/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:32:30 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/17 03:54:11 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	visualize(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		operations;

	operations = 0;
	while (1)
	{
		write(1, "\n", 1);
		write(1, "Input operation: ", 17);
		line = get_next_line(0);
		if (!ft_strncmp(line, "rra", 3))
		{
			operations++;
			rra(stack_a, 0);
		}
		else if (!ft_strncmp(line, "rrb", 3))
		{
			operations++;
			rrb(stack_b, 0);
		}
		else if (!ft_strncmp(line, "rrr", 3))
		{
			operations++;
			rrr(stack_a, stack_b);
		}
		else if (!ft_strncmp(line, "sa", 2))
		{
			operations++;
			sa(stack_a, 0);
		}
		else if (!ft_strncmp(line, "sb", 2))
		{
			operations++;
			sb(stack_b, 0);
		}
		else if (!ft_strncmp(line, "ss", 2))
		{
			operations++;
			ss(stack_a, stack_b);
		}
		else if (!ft_strncmp(line, "pa", 2))
		{
			operations++;
			pa(stack_a, stack_b);
		}
		else if (!ft_strncmp(line, "pb", 2))
		{
			operations++;
			pb(stack_a, stack_b);
		}
		else if (!ft_strncmp(line, "ra", 2))
		{
			operations++;
			ra(stack_a, 0);
		}
		else if (!ft_strncmp(line, "rb", 2))
		{
			operations++;
			rb(stack_b, 0);
		}
		else if (!ft_strncmp(line, "rr", 2))
		{
			operations++;
			rr(stack_a, stack_b);
		}
		else if (!ft_strncmp(line, "q", 1))
			break ;
		system("clear");
		printf("OPERATION: %s\n", line);
		printf("stack a: \n");
		print_stack(*stack_a);
		printf("stack b: \n");
		print_stack(*stack_b);
		printf("\nsize of stack A is: %d\n", ft_lstsize(*stack_a));
		printf("size of stack B is: %d\n", ft_lstsize(*stack_b));
		printf("TOTAL OPERATIONS: %d\n", operations);
	}
}

void	print_stack(t_list *head)
{
	t_list	*temp;	

	temp = head;
	while (temp)
	{
		printf("contents: %d\n", *(int *)(temp)->content);
		temp = temp->next;
	}
}

void	format_printf(t_list *stack_a, t_list *stack_b)
{
	printf("stack a: \n");
	print_stack(stack_a);
	printf("stack b: \n");
	print_stack(stack_b);
	if (!stack_a)
		printf("NULL");
	printf("\nsize of stack A is: %d\n", ft_lstsize(stack_a));
	printf("size of stack B is: %d\n\n", ft_lstsize(stack_b));
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = create_stack(argv);
	stack_b = NULL;
	if (error_checking(stack_a))
		return (0);
//	visualize(&stack_a, &stack_b);
//	shellsort(&stack_a, &stack_b, argc - 1);
	format_printf(stack_a, stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
