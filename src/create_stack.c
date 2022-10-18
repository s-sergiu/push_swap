/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:46:39 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/18 22:56:49 by ssergiu          ###   ########.fr       */
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
		if (!check_non_numeric(split[j]))
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
