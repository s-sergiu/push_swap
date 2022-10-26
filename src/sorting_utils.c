/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:02:57 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/26 05:44:28 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

t_list	*get_max_number(t_list *head)
{
	t_list	*cursor;
	t_list	*min;

	cursor = head;
	min = head;
	while (cursor)
	{
		if (*(int *)(min)->content < *(int *)(cursor)->content)
			min = cursor;
		cursor = cursor->next;
	}
	return (min);
}

t_list	*get_lowest_number(t_list *head)
{
	t_list	*cursor;
	t_list	*min;

	cursor = head;
	min = head;
	while (cursor)
	{
		if (*(int *)(min)->content > *(int *)(cursor)->content)
			min = cursor;
		cursor = cursor->next;
	}
	return (min);
}

t_list	*find_highest_val(t_list *head)
{
	t_list	*cursor;
	t_list	*max;

	cursor = head;
	while (head)
	{
		if (head->rev_sorted_index < 1)
			max = head;
		head = head->next;
	}
	while (cursor)
	{
		if (cursor->rev_sorted_index < 1)
			if (*(int *)(max)->content < *(int *)(cursor)->content)
				max = cursor;
		cursor = cursor->next;
	}
	return (max);
}

t_list	*find_lowest_val(t_list *head)
{
	t_list	*cursor;
	t_list	*min;

	cursor = head;
	while (head)
	{
		if (head->sorted_index < 1)
			min = head;
		head = head->next;
	}
	while (cursor)
	{
		if (cursor->sorted_index < 1)
			if (*(int *)(min)->content > *(int *)(cursor)->content)
				min = cursor;
		cursor = cursor->next;
	}
	return (min);
}

t_list	*get_closest_to_index(t_list **quarter, t_list **head)
{
	t_list	*cursor;
	t_list	*temp;
	int		min;

	cursor = *quarter;
	temp = *quarter;
	min = 0;
	while (cursor)
	{
		closest_to_index_loop(cursor, &temp, head, &min);
		cursor = cursor->next;
	}
	remove_from_list(temp->content, quarter);
	return (temp);
}
