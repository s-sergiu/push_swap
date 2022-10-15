/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:39:31 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/15 01:54:00 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../src/libft/libft.h"

int			check_input(char *argv);
t_list		*create_stack(char **argv);
t_list		*create_empty(int argc);
void		print_stack(t_list *list);
void		sa(t_list **head);
void		sb(t_list **head);
void		ss(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		ra(t_list **head);
void		rb(t_list **head);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **head);
void		rrb(t_list **head);
void		rrr(t_list **stack_a, t_list **stack_b);

#endif
