/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:33:34 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 18:54:01 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

int	has_non_numeric_vals(char *argv)
{
	int	i;

	i = -1;
	if (argv[0] == '-' && argv[1] == 0)
		return (0);
	if (argv[0] == '-')
		i++;
	while (argv[++i] != 0)
		if (!((ft_isdigit(argv[i]) || argv[i] == 32) && argv[i] != '-'))
			return (0);
	return (1);
}

int	has_duplicate_numbers(t_list *head)
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

int	is_sorted(t_list *head)
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

int	stack_is_invalid(t_list *head)
{
	if (!head)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_lstsize(head) < 2)
		return (1);
	if (has_duplicate_numbers(head))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sorted(head))
		return (1);
	return (0);
}
