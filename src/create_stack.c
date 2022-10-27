/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:46:39 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 15:10:13 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

t_list	*create_first_quarter(t_list **head, int quart, int initial_size)
{
	int		i;
	t_list	*quarter;
	t_list	*cursor;

	quarter = NULL;
	i = quart - (initial_size - 1);
	while (i <= quart)
	{
		cursor = get_node_by_sorted_index(*head, i++);
		ft_lstadd_back(&quarter, ft_lstnew(cursor->content));
	}
	return (quarter);
}

t_list	*create_first_quarter_rev(t_list **head, int quart, int initial_size)
{
	int		i;
	t_list	*quarter;
	t_list	*cursor;

	quarter = NULL;
	i = quart - (initial_size - 1);
	while (i <= quart)
	{
		cursor = get_node_by_rev_index(*head, i++);
		ft_lstadd_back(&quarter, ft_lstnew(cursor->content));
	}
	return (quarter);
}
