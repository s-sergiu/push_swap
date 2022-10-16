/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:33:34 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/16 02:33:07 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
		free(str[i]);
	free(str);
}

int	xcheck_input(char *argv)
{
	int	i;

	i = -1;
	if (argv[0] == '-')
		i++;
	while (argv[++i] != 0)
		if (!((ft_isdigit(argv[i]) || argv[i] == 32) && argv[i] != '-'))
			return (0);
	return (1);
}

t_list	*create_stack(char **argv)
{
	int		i;
	int		j;
	t_list	*head;
	t_list	*new;
	char	**split;
	int		*content;

	head = NULL;
	i = 0;
	while (argv[++i] != 0)
	{
		split = ft_split(argv[i], ' ');
		j = -1;
		while (split[++j] != 0)
		{
			if (!xcheck_input(split[j]))
				return (NULL);
			content = (int *)malloc(sizeof(int) * 1);
			*content = ft_atoi(split[j]);
			new = ft_lstnew(content);
			ft_lstadd_back(&head, new);
		}
	free_split(split);
	}
	return (head);
}

int	check_for_duplicates(t_list *head)
{
	t_list *outer;
	t_list *inner;

	outer = head;
	while(outer)
	{
		inner = outer->next;
		while(inner)
		{
			if (*(int *)(outer)->content == *(int *)(inner)->content)
				return (1);
			inner = inner->next;	
		}
		outer = outer->next;
	}
	return (0);
}

int	check_if_ordered(t_list *head)
{
	t_list *curr;

	curr = head;
	while (curr->next)
	{
		if (!(*(int *)(curr)->content < *(int *)(curr)->next->content))
			return (0);
		curr = curr->next;
	}
	return (1);
}
