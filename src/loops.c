/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 05:43:55 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 18:52:37 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	closest_to_index_loop(t_list *cursor, t_list **temp,
			t_list **head, int *min)
{
	int		size;
	t_list	*number;

	number = get_node_by_content(*head, cursor->content);
	size = ft_lstsize(*head);
	if (number->index <= (size / 2))
	{
		if (*min <= ((size / 2) - (number->index)))
		{
			*min = ((size / 2) - (number->index));
			*temp = number;
		}
	}
	else
	{
		if (*min <= (size / 2) - ((size + 1) - number->index))
		{
			*min = ((size / 2) - ((size + 1) - number->index));
			*temp = number;
		}
	}
}

void	approximity_b(t_list *closest, t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (closest->index == 1)
		pa(stack_a, stack_b, 0);
	while (closest->index > 1)
	{
		size = ft_lstsize(*stack_b);
		if ((size / 2) >= closest->index)
			rb(stack_b, 0);
		else
			rrb(stack_b, 0);
		index_list(*stack_b);
		if (closest->index == 1)
			pa(stack_a, stack_b, 0);
	}
}

void	approximity(t_list *closest, t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (closest->index == 1)
		pb(stack_a, stack_b, 0);
	while (closest->index > 1)
	{
		size = ft_lstsize(*stack_a);
		if ((size / 2) >= closest->index)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
		index_list(*stack_a);
		if (closest->index == 1)
			pb(stack_a, stack_b, 0);
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
