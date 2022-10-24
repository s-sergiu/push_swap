/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:02:57 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/24 04:52:10 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

t_list *get_number_index(t_list *head, void *number)
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

t_list	*get_list_index_one(t_list *head, int number)
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

t_list	*get_list_index(t_list *head, int number)
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

int	get_max_number(t_list *head)
{
	t_list	*cursor;
	t_list	*min;

	cursor = head;
	min = head;
	while (cursor)
	{
		if (*(int *)(min)->content <  *(int *)(cursor)->content)
			min = cursor;
		cursor = cursor->next;
	}
	return (min->index);
}

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

void	sorted_index_list(t_list *head)
{
	int		i;
	int		size;

	i = 1;
	size = ft_lstsize(head) + 1;
	while (i < size)
		(find_lowest_val(head))->sorted_index = i++;
}

int get_closest_to_index(t_list **quarter, t_list **head)
{
	t_list	*cursor;
	t_list	*number;
	int		size;
	int		temp;
	int		min;
	void	*numberdel;

	cursor = *quarter;
	min = 0;
	size = ft_lstsize(*head);
	while (cursor)
	{
		number = get_number_index(*head, cursor->content);
		if (number->index <= (size / 2))
		{
			if (min <= ((size/2) - (number->index)))
			{
				min = ((size/2) - (number->index));
				temp = number->index;
				numberdel = number->content;
			}
		}
		else
		{
			if (min <= (size/2) - ((size + 1) - number->index))
			{
				min = ((size/2) - ((size + 1) - number->index));
				temp = number->index;
				numberdel = number->content;
			}
		}
		cursor = cursor->next;
	}
	remove_from_list(numberdel, quarter);
	return (temp);
}

void	remove_from_list(void *number, t_list **head)
{
	t_list	*cursor;
	t_list	*temp;

	cursor = *head;
	if (cursor->content == number)
	{
		*head = (*head)->next;
		cursor = NULL;
	}
	while (cursor)
	{
		if (cursor->next->content == number)
		{
			temp = cursor->next;
			cursor->next = cursor->next->next;
			temp->next = NULL;
			temp = NULL;
			break;
		}
		cursor = cursor->next;
	}
}
