/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:10:48 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 18:53:26 by ssergiu          ###   ########.fr       */
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

void	ss(t_list **stack_a, t_list **stack_b, int flag)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	if (!flag)
		write(1, "ss\n", 3);
}
