/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 05:32:58 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 15:13:58 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

t_list	*get_node_by_content(t_list *head, void *number)
{
	t_list	*cursor;

	cursor = head;
	while (cursor)
	{
		if (cursor->content == number)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}

t_list	*get_node_by_index(t_list *head, int number)
{
	t_list	*cursor;

	cursor = head;
	while (cursor)
	{
		if (cursor->index == number)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}

t_list	*get_node_by_rev_index(t_list *head, int number)
{
	t_list	*cursor;

	cursor = head;
	while (cursor)
	{
		if (cursor->rev_sorted_index == number)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}

t_list	*get_node_by_sorted_index(t_list *head, int number)
{
	t_list	*cursor;

	cursor = head;
	while (cursor)
	{
		if (cursor->sorted_index == number)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}

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
