/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:11:42 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/19 23:05:22 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/checker.h"

void	ra(t_list **head, int flag)
{
	t_list	*temp;

	if (ft_lstsize(*head) < 2)
		return ;
	temp = *head;
	*head = (*head)->next;
	temp->next = NULL;
	ft_lstadd_back(head, temp);
	if (!flag)
		write(1, "ra\n", 3);
}

void	rb(t_list **head, int flag)
{
	t_list	*temp;

	if (ft_lstsize(*head) < 2)
		return ;
	temp = *head;
	*head = temp->next;
	temp->next = NULL;
	ft_lstadd_back(head, temp);
	if (!flag)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int flag)
{
	rb(stack_b, 1);
	ra(stack_a, 1);
	if (!flag)
		write(1, "rr\n", 3);
}
