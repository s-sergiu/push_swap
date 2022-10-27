/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:32:30 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 12:55:42 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	init_indexes(t_list **head)
{
	t_list	*cursor;

	cursor = *head;
	while (cursor)
	{
		cursor->index = -1;
		cursor->sorted_index = -1;
		cursor->rev_sorted_index = -1;
		cursor = cursor->next;
	}
}

void	sort_by_size(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 3)
	{
		while (!is_sorted(*stack_a))
			sort_three(stack_a);
	}
	else if (size == 2)
		sa(stack_a, 0);
	else if (size < 13)
		sort(stack_a, stack_b);
	else if (size > 12)
		bigsort(stack_a, stack_b);
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
	stack_a = create_stack(argv);
	init_indexes(&stack_a);
	if (stack_is_invalid(stack_a))
	{
		ft_lstclear(&stack_a, free);
		return (0);
	}
	size = ft_lstsize(stack_a);
	sorted_index_list(stack_a);
	reverse_sorted_index_list(stack_a);
	sort_by_size(&stack_a, &stack_b, size);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
