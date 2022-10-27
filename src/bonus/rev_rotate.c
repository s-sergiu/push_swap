/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:12:01 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 18:54:16 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

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

void	rrr(t_list **stack_a, t_list **stack_b, int flag)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	if (!flag)
		write(1, "rrr\n", 4);
}
