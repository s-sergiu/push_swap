/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:45:31 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/18 15:45:57 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

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

void	rr(t_list **stack_a, t_list **stack_b)
{
	rb(stack_b, 1);
	ra(stack_a, 1);
	write(1, "rr\n", 3);
}
