/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:33:34 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 18:52:17 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * Checks inside single string if ist a valid number or not;
 */
int	has_non_numeric_vals(char *argv)
{
	int	i;

	i = -1;
	if ((argv[0] == '-' || argv[0] == '+') && argv[1] == 0)
		return (0);
	if (argv[0] == '-' || argv[0] == '+')
		i++;
	while (argv[++i] != 0)
		if (!(ft_isdigit(argv[i]) || argv[i] == 32))
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

int	is_sorted_reverse(t_list *head)
{
	t_list	*curr;

	curr = head;
	while (curr->next)
	{
		if (!(*(int *)(curr)->content > *(int *)(curr)->next->content))
			return (0);
		curr = curr->next;
	}
	return (1);
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
