/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:18:08 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 18:48:37 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three_b(t_list **head)
{
	int	first_element;
	int	second_element;
	int	third_element;

	first_element = *(int *)(*(head))->content;
	second_element = *(int *)(*(head))->next->content;
	third_element = *(int *)(*(head))->next->next->content;
	if ((first_element < second_element) && (first_element < third_element))
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
		ra(head, 0);
		if (!is_sorted(*head))
			sa(head, 0);
	}
	else if (first_element < second_element)
	{
		rra(head, 0);
		if (!is_sorted(*head))
			sa(head, 0);
	}
	if (!is_sorted(*head))
		sa(head, 0);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*index;

	while (ft_lstsize(*stack_a) > 3)
	{
		index_list(*stack_a);
		index = get_lowest_number(*stack_a);
		approximity(index, stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, 0);
}

void	sort_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*index;

	while (ft_lstsize(*stack_b) > 3)
	{
		index_list(*stack_b);
		index = get_max_number(*stack_b);
		approximity_b(index, stack_a, stack_b);
	}
	if (!is_sorted_reverse(*stack_b))
		sort_three_b(stack_b);
	while (ft_lstsize(*stack_b) > 0)
		pa(stack_a, stack_b, 0);
}

void	bigsort(t_list **stack_a, t_list **stack_b)
{
	t_list	*quarter;
	t_list	*closest;
	int		quart;
	int		initial_size;

	initial_size = ft_lstsize(*stack_a) / get_divisor(ft_lstsize(*stack_a));
	quart = initial_size;
	while (*stack_a)
	{
		if (ft_lstsize(*stack_a) < initial_size)
		{
			while (*stack_a)
				pb(stack_a, stack_b, 0);
			break ;
		}
		quarter = create_chunk(stack_a, quart, initial_size);
		while (quarter)
		{
			closest = get_closest_to_index(&quarter, stack_a);
			approximity(closest, stack_a, stack_b);
			remove_from_list(closest->content, &quarter);
		}
		quart += initial_size;
	}						
	sort_b(stack_a, stack_b);
}
