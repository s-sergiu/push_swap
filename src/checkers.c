/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:33:34 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/18 15:55:34 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

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

int	check_for_duplicates(t_list *head)
{
	t_list	*outer;
	t_list	*inner;

	outer = head;
	while (outer)
	{
		inner = outer->next;
		while (inner)
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
	t_list	*curr;

	curr = head;
	while (curr->next)
	{
		if (!(*(int *)(curr)->content < *(int *)(curr)->next->content))
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	error_checking(t_list *head)
{
	if (!head)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (check_for_duplicates(head))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (check_if_ordered(head))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
