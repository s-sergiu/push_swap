/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:02:57 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/21 06:55:47 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	get_lowest_number(t_list *head)
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
	return (min->index);
}

void	index_list(t_list *head)
{
	int		i;
	t_list	*cursor;

	i = 1;
	cursor = head;
	while (cursor)
	{
		cursor->index = i++;
		cursor = cursor->next;
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
