/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:39:50 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/15 22:15:07 by ssergiu          ###   ########.fr       */
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

void	rra(t_list **head, int flag)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_lstsize(*head) < 2)
		return ;
	temp = *head;
	while (temp->next->next)
		temp = temp->next;
	temp2 = temp->next;
	ft_lstadd_front(head, temp2);
	temp->next = NULL;
	if (!flag)
		write(1, "rra\n", 4);
}

void	rrb(t_list **head, int flag)
{
	t_list	*temp;
	t_list	*temp2;

	if (ft_lstsize(*head) < 2)
		return ;
	temp = *head;
	while (temp->next->next)
		temp = temp->next;
	temp2 = temp->next;
	ft_lstadd_front(head, temp2);
	temp->next = NULL;
	if (!flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	write(1, "rrr\n", 4);
}
