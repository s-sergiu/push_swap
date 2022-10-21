/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:02:57 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/21 04:58:18 by ssergiu          ###   ########.fr       */
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
