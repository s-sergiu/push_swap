/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:18:08 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/19 01:51:13 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	shellsort(t_list **stack_a, t_list **stack_b)
{
	t_list	*cursor;

	while (!is_sorted(*stack_a))
	{
		cursor = *stack_a;
		while (cursor)
		{
			if (ft_lstsize(cursor) == 1)
				pb(stack_a, stack_b);
			if (*(int *)(cursor)->content < *(int *)(cursor)->next->content)
				pb(stack_a, stack_b);
			else
			{
				sa(stack_a, 0);
				pb(stack_a, stack_b);
			}
			cursor = *stack_a;
		}
		cursor = *stack_b;
		while (cursor)
		{
			if (ft_lstsize(cursor) == 1)
				pa(stack_a, stack_b);
			if (*(int *)(cursor)->content > *(int *)(cursor)->next->content)
				pa(stack_a, stack_b);
			else
			{
				sb(stack_b, 0);
				pa(stack_a, stack_b);
			}
			cursor = *stack_b;
		}
	}
}

void	sort_three(t_list **stack_a)
{
	int	first_element;
	int	second_element;

	first_element = *(int *)(*(stack_a))->content;
	second_element = *(int *)(*(stack_a))->next->content;
	if ((first_element == 3 && second_element == 1)
		|| (first_element == 3 && second_element == 2))
	{
		ra(stack_a, 0);
		if (!is_sorted(*stack_a))
			sa(stack_a, 0);
	}
	else if ((first_element == 2 && second_element == 3)
		|| (first_element == 1 && second_element == 3))
	{
		rra(stack_a, 0);
		if (!is_sorted(*stack_a))
			sa(stack_a, 0);
	}
	else
		sa(stack_a, 0);
}
