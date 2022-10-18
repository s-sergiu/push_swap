/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:39:50 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/18 15:44:52 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	sa(t_list **head, int flag)
{
	t_list	*temp;

	if (ft_lstsize(*head) < 2)
		return ;
	temp = *head;
	*head = temp->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	if (!flag)
		write(1, "sa\n", 3);
}

void	sb(t_list **head, int flag)
{
	t_list	*temp;

	if (ft_lstsize(*head) < 2)
		return ;
	temp = *head;
	*head = temp->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	if (!flag)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	write(1, "ss\n", 3);
}

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
