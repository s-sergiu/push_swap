/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:11:03 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/18 23:11:29 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_b) == 0)
		return ;
	temp = *stack_b;
	*stack_b = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_a, temp);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (ft_lstsize(*stack_a) == 0)
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_b, temp);
	write(1, "pb\n", 3);
}
