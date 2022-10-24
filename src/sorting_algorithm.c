/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:18:08 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/24 10:10:57 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

/*
 * Hardcoded sorting list of size(3);
 */
void	sort_three_b(t_list **head)
{
	int	first_element;
	int	second_element;
	int	third_element;

	first_element = *(int *)(*(head))->content;
	second_element = *(int *)(*(head))->next->content;
	third_element = *(int *)(*(head))->next->next->content;
	if ((first_element <  second_element) && (first_element < third_element))
	{
		rb(head, 0);
		if (!is_sorted_reverse(*head))
			sb(head, 0);
	}
	else if (first_element > second_element)
	{
		rrb(head, 0);
		if (!is_sorted_reverse(*head))
			sb(head, 0);
	}
	else
		sb(head, 0);
}
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

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	proximity;
	int	size;

	while (ft_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		index_list(*stack_a);
		size = ft_lstsize(*stack_a);
		index = get_lowest_number(*stack_a);
		proximity = size / 2;
		while (index == 1)
		{
			pb(stack_a, stack_b, 0);
			index_list(*stack_a);
			index = get_lowest_number(*stack_a);
			proximity = size / 2;
		}
		if (proximity >= index)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
	sort_three(stack_a);
	while (ft_lstsize(*stack_b) > 3 && !is_sorted(*stack_b))
		pa(stack_a, stack_b, 0);
	pa(stack_a, stack_b, 0);
	pa(stack_a, stack_b, 0);
	pa(stack_a, stack_b, 0);
}

void	sort_b(t_list **stack_a, t_list **stack_b)
{
	int	index;
	int	proximity;
	int	size;

	size = ft_lstsize(*stack_b);
	while (size > 3)
	{
		index_list(*stack_b);
		size = ft_lstsize(*stack_b);
		index = get_max_number(*stack_b);
		proximity = size / 2;
		if (index == 1)
		{
			pa(stack_a, stack_b, 0);
			size = ft_lstsize(*stack_b);
			index_list(*stack_b);
			index = get_max_number(*stack_b);
			proximity = size / 2;
		}
		if (size < 4)
			break;
		if (proximity >= index)
			rb(stack_b, 0);
		else
			rrb(stack_b, 0);
	}
	if (!is_sorted_reverse(*stack_b))
		sort_three_b(stack_b);
	while(ft_lstsize(*stack_b) > 0)
		pa(stack_a, stack_b, 0);
}

void	bigsort(t_list **stack_a, t_list **stack_b)
{
	t_list	*quarter;
	int		closest;
	t_list	*index;
	int		size;
	int		quart;
	int		proximity;
	int		initial_size;
	int		init;

	size = ft_lstsize(*stack_a);
	init = size;
	initial_size = size / 15;
	quart = initial_size;
	while(*stack_a)
	{
		if (quart > init)
		{
			while(*stack_a)
			{
				pb(stack_a, stack_b, 0);
			}
			break;
		}
		quarter = create_first_quarter(stack_a, quart, initial_size);
		while (quarter)
		{
			index_list(*stack_a);
			closest = get_closest_to_index(&quarter, stack_a);
			index = get_list_index_one(*stack_a, closest);
			while (index->index != 1)
			{
				size = ft_lstsize(*stack_a);
				proximity = size / 2;
				if (proximity >= index->index)
					ra(stack_a, 0);
				else
					rra(stack_a, 0);
				index_list(*stack_a);
			}
			if (index->index == 1)
			{
				pb(stack_a, stack_b, 0);
				size = ft_lstsize(*stack_a);
				if (size == 1)
				{
					pb(stack_a, stack_b, 0);
					break;
				}
				index_list(*stack_a);
				proximity = size / 2;
			}
		}
		quart += initial_size;
	}						
	sort_b(stack_a, stack_b);
}
