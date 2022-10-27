/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:09:30 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 18:53:52 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i] != 0)
		free(split[i]);
	free(split);
}

void	clear_and_free_split(t_list **head, char **split)
{
	if (*head)
		ft_lstclear(head, free);
	free_split(split);
}

void	remove_from_list(void *number, t_list **head)
{
	t_list	*cursor;
	t_list	*temp;

	cursor = *head;
	if (cursor->content == number)
	{
		*head = (*head)->next;
		free(cursor);
		cursor = NULL;
	}
	while (cursor)
	{
		if (cursor->next->content == number)
		{
			temp = cursor->next;
			cursor->next = cursor->next->next;
			free(temp);
			temp = NULL;
			break ;
		}
		cursor = cursor->next;
	}
}
