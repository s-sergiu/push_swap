/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:39:31 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/21 05:04:00 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../src/libft/libft.h"

void		sa(t_list **head, int flag);
void		sb(t_list **head, int flag);
void		ss(t_list **stack_a, t_list **stack_b, int flag);
void		pb(t_list **stack_a, t_list **stack_b, int flag);
void		pa(t_list **stack_a, t_list **stack_b, int flag);
void		ra(t_list **head, int flag);
void		rb(t_list **head, int flag);
void		rr(t_list **stack_a, t_list **stack_b, int flag);
void		rra(t_list **head, int flag);
void		rrb(t_list **head, int flag);
void		rrr(t_list **stack_a, t_list **stack_b, int flag);
void		sort_three(t_list **head);
void		index_list(t_list *head);
void		sergiusort(t_list **stack_a, t_list **stack_b);
t_list		*create_stack(char **argv);
int			has_non_numeric_vals(char *argv);
int			get_lowest_number(t_list *head);
int			has_duplicate_numbers(t_list *head);
int			is_sorted(t_list *head);
int			stack_is_invalid(t_list *head);

#endif
