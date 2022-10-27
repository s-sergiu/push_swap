/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:11:38 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 15:11:45 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
