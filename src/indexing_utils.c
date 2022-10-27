/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 05:35:40 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 18:48:21 by ssergiu          ###   ########.fr       */
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

void	reverse_sorted_index_list(t_list *head)
{
	int		i;
	int		size;

	i = 1;
	size = ft_lstsize(head) + 1;
	while (i < size)
		(find_highest_val(head))->rev_sorted_index = i++;
}

void	sorted_index_list(t_list *head)
{
	int		i;
	int		size;

	i = 1;
	size = ft_lstsize(head) + 1;
	while (i < size)
		(find_lowest_val(head))->sorted_index = i++;
}
