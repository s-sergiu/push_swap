/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:32:30 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/24 14:22:42 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	print_list(t_list **head)
{
	t_list *cursor;
	int	i;

	cursor = *head;
	i = 0;
	while (cursor)
	{
		printf("cursor at %d is %d with index %d and sorted index %d.\n", 
			i, *(int *)(cursor)->content, cursor->index, cursor->sorted_index);
		i++;
		cursor = cursor->next;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argv[1][0] == 0)
		return (0);
	stack_a = create_stack(argv);
	if (stack_is_invalid(stack_a))
	{
		ft_lstclear(&stack_a, free);
		return (0);
	}
	size = ft_lstsize(stack_a);
	sorted_index_list(stack_a);
	if (size == 3)
	{
		while (!is_sorted(stack_a))
			sort_three(&stack_a);
	}
	else if (size == 2)
		sa(&stack_a, 0);
	else if (size < 13)
		sort(&stack_a, &stack_b);
	else if (size > 12)
		bigsort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
