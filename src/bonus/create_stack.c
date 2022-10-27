/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:46:39 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 18:53:47 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

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

int	create_stack_loop(t_list **head, char **split)
{
	int		j;
	long	*content;

	j = -1;
	while (split[++j] != 0)
	{
		if (!has_non_numeric_vals(split[j]))
			return (0);
		content = (long *)malloc(sizeof(long) * 1);
		if (!content)
			return (0);
		*content = ft_atoi(split[j]);
		if (*content < -2147483648 || *content > 2147483647)
		{
			free(content);
			return (0);
		}
		ft_lstadd_back(head, ft_lstnew(content));
	}
	return (1);
}

t_list	*create_stack(char **argv)
{
	int		i;
	t_list	*head;
	char	**split;

	head = NULL;
	i = 0;
	while (argv[++i] != 0)
	{
		split = ft_split(argv[i], ' ');
		if (split[0] == 0)
		{
			clear_and_free_split(&head, split);
			return (NULL);
		}
		if (!create_stack_loop(&head, split))
		{
			clear_and_free_split(&head, split);
			return (NULL);
		}
		free_split(split);
	}
	return (head);
}
