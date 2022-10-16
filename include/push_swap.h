/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:39:31 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/16 02:26:15 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <curses.h>
# include "../src/libft/libft.h"

int			xcheck_input(char *argv);
char		*get_next_line(int fd);
t_list		*create_stack(char **argv);
t_list		*create_empty(int argc);
void		print_stack(t_list *list);
void		sa(t_list **head, int flag);
void		sb(t_list **head, int flag);
void		ss(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		ra(t_list **head, int flag);
void		rb(t_list **head, int flag);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **head, int flag);
void		rrb(t_list **head, int flag);
void		rrr(t_list **stack_a, t_list **stack_b);
void		visualize(t_list **stack_a, t_list **stack_b);
int			check_for_duplicates(t_list *head);
int			check_if_ordered(t_list *head);

#endif