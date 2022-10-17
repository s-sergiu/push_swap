/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:18:08 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/17 04:09:35 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	shellsort(t_list **stack_a, t_list **stack_b, int argc)
{
	t_list	*cursor;

	while (!check_if_ordered(*stack_a))
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

void	sergiusort(t_list **stack_a, t_list **stack_b, int argc)
{
	int	*first;
	int	*second;
	int	*last;
}
