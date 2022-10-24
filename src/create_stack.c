/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:46:39 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/24 04:25:42 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i] != 0)
		free(split[i]);
	free(split);
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
	if (argv[i][0] == 0)
		return (NULL);
	while (argv[++i] != 0)
	{
		split = ft_split(argv[i], ' ');
		if (split[0] == 0)
		{
			free_split(split);
			return (NULL);
		}
		if (!create_stack_loop(&head, split))
		{
			if (head)
				ft_lstclear(&head, free);
			free_split(split);
			return (NULL);
		}
		free_split(split);
	}
	return (head);
}

t_list *create_first_quarter(t_list **head, int quart, int initial_size)
{
	int	i;
	t_list *quarter;
	t_list *cursor;

	quarter = NULL;
	i = quart - (initial_size - 1);
	while(i <= quart) 
	{
		cursor = get_list_index(*head, i++);
		ft_lstadd_back(&quarter, ft_lstnew(cursor->content));
	}
	return (quarter);
}
