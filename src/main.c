/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:32:30 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/15 02:50:52 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	print_stack(t_list *list)
{
	t_list	*temp;	

	temp = list;
	while (temp)
	{
		printf("contents: %s\n", temp->content);
		temp = temp->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = create_stack(argv);
	stack_b = NULL;
	printf("Stack A: \n");
	print_stack(stack_a);
	if (!stack_a)
		printf("NULL");
	printf("size of stack A is: %d\n", ft_lstsize(stack_a));
	printf("size of stack B is: %d\n", ft_lstsize(stack_b));
	printf("stack a: \n");
	rra(&stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	rrb(&stack_b);
	sb(&stack_b);
	pa(&stack_a, &stack_b);
	sb(&stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	print_stack(stack_a);
	printf("stack b: \n");
	print_stack(stack_b);
	printf("size of stack A is: %d\n", ft_lstsize(stack_a));
	printf("size of stack B is: %d\n", ft_lstsize(stack_b));
	return (0);
}
