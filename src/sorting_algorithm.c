/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:18:08 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/21 06:33:05 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	sergiusort(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	proximity;
	int	size;

	while (ft_lstsize(*stack_a) > 3)
	{
		index_list(*stack_a);
		size = ft_lstsize(*stack_a);
		index = get_lowest_number(*stack_a);
		proximity = size / 2;
		if (index == 1)
			pb(stack_a, stack_b, 0);
		if (proximity > index)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
	sort_three(stack_a);
	while (ft_lstsize(*stack_b) > 3)
		pa(stack_a, stack_b, 0);
	sort_three(stack_b);
	pa(stack_a, stack_b, 0);
	pa(stack_a, stack_b, 0);
	pa(stack_a, stack_b, 0);
	
}

/*
 * Hardcoded sorting list of size(3);
 */
void	sort_three(t_list **head)
{
	int	first_element;
	int	second_element;
	int	third_element;

	first_element = *(int *)(*(head))->content;
	second_element = *(int *)(*(head))->next->content;
	third_element = *(int *)(*(head))->next->next->content;
	if ((first_element > second_element) && (first_element > third_element))
	{
		if (second_element < third_element)
			ra(head, 0);
		if (!is_sorted(*head))
			sa(head, 0);
	}
	else if ((first_element < second_element)
		&& (first_element < second_element))
	{
		if (second_element > third_element)
			rra(head, 0);
		if (!is_sorted(*head))
			sa(head, 0);
	}
	else
		sa(head, 0);
}

/*
 * Hardcoded sorting list of size(3) for stack_b (reverse order);
 */
void	reverse_sort_three(t_list **head)
{
	int	first_element;
	int	second_element;

	first_element = *(int *)(*(head))->content;
	second_element = *(int *)(*(head))->next->content;
	if ((first_element > second_element) || (first_element > second_element))
	{
		rrb(head, 0);
		if (!is_sorted(*head))
			sb(head, 0);
	}
	else if ((first_element < second_element)
		|| (first_element < second_element))
	{
		sb(head, 0);
		if (!is_sorted(*head))
			rrb(head, 0);
	}
	else
		rb(head, 0);
}
