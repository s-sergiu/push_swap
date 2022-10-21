/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:18:08 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/21 02:55:47 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

/*
 * Hardcoded sorting list of size(3);
 */
void	sort_three(t_list **stack_a)
{
	int	first_element;
	int	second_element;
	int third_element;

	first_element = *(int *)(*(stack_a))->content;
	second_element = *(int *)(*(stack_a))->next->content;
	third_element = *(int *)(*(stack_a))->next->next->content;
	if ((first_element > second_element) && (first_element > third_element))
	{
		if (second_element <  third_element)
			ra(stack_a, 0);
		if (!is_sorted(*stack_a))
			sa(stack_a, 0);
	}
	else if ((first_element < second_element) 
		&& (first_element < second_element))
	{
		if (second_element > third_element)
			rra(stack_a, 0);
		if (!is_sorted(*stack_a))
			sa(stack_a, 0);
	}
	else
		sa(stack_a, 0);
}

void	reverse_sort_three(t_list **stack_a)
{
	int	first_element;
	int	second_element;

	first_element = *(int *)(*(stack_a))->content;
	second_element = *(int *)(*(stack_a))->next->content;
	if ((first_element > second_element) || (first_element > second_element))
	{
		rra(stack_a, 0);
		if (!is_sorted(*stack_a))
			sa(stack_a, 0);
	}
	else if ((first_element < second_element) 
		|| (first_element < second_element))
	{
		sa(stack_a, 0);
		if (!is_sorted(*stack_a))
			rra(stack_a, 0);
	}
	else
		ra(stack_a, 0);
}

void	shellsort(t_list **stack_a, t_list **stack_b)
{
	t_list	*cursor_a;
	t_list	*cursor_b;
	int		*first;
	int		*second;
//	int		*last;

	while (!is_sorted(*stack_a))
	{
		cursor_a = *stack_a;
		while (cursor_a)
		{
			if (ft_lstsize(cursor_a) == 1)
				pb(stack_a, stack_b, 0);
			if (ft_lstsize(cursor_a) == 3)
			{
				sort_three(&cursor_a);
				break ;
			}
			first = (int*)(cursor_a)->content;
			second = (int *)(cursor_a)->next->content;
//			last = (int *)ft_lstlast(cursor)->content;
			if (*(first) < *(second))
			{
//				if (*last < *first)
//					rra(stack_a, 0);
				pb(stack_a, stack_b, 0);
			}
			else
			{
				sa(stack_a, 0);
				pb(stack_a, stack_b, 0);
			}

			cursor_a = *stack_a;
		}
		cursor_b = *stack_b;
		while (cursor_b)
		{
			if (ft_lstsize(cursor_b) == 1)
				pa(stack_a, stack_b, 0);
			if (ft_lstsize(cursor_b) == 3)
			{
				sort_three(&cursor_b);
				break ;
			}
			first = (int*)(cursor_b)->content;
			second = (int *)(cursor_b)->next->content;
//			last = (int *)ft_lstlast(cursor)->content;
			if (*(first) > *(second))
			{
//				if (*last < *first)
//					rrb(stack_a, 0);
				pa(stack_a, stack_b, 0);
			}
			else
			{
				sb(stack_b, 0);
				pa(stack_a, stack_b, 0);
			}
			cursor_b = *stack_b;
		}
	}
}

t_list	*find_lowest_val(t_list *head)
{
	t_list	*cursor;
	t_list	*min;

	cursor = head;
	while (head)
	{
		if (head->index < 1)
			min = head;
		head = head->next;
	}
	while (cursor)
	{
		if (cursor->index < 1)
			if (*(int *)(min)->content > *(int *)(cursor)->content)
				min = cursor;
		cursor = cursor->next;
	}
	return (min);
}

void	index_list(t_list *head)
{
	int		i;
	int		size;

	i = 1;
	size = ft_lstsize(head) + 1;
	while (i < size)
		(find_lowest_val(head))->index = i++;

}
