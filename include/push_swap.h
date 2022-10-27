/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:39:31 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 12:55:01 by ssergiu          ###   ########.fr       */
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
void		sort(t_list **stack_a, t_list **stack_b);
void		bigsort(t_list **stack_a, t_list **stack_b);
void		sorted_index_list(t_list *head);
void		reverse_sorted_index_list(t_list *head);
void		remove_from_list(void *number, t_list **head);
void		approximity_b(t_list *closest, t_list **stack_a, t_list **stack_b);
void		approximity(t_list *closest, t_list **stack_a, t_list **stack_b);
void		closest_to_index_loop(t_list *cursor, t_list **temp,
				t_list **head, int *min);
t_list		*find_highest_val(t_list *head);
t_list		*find_lowest_val(t_list *head);
t_list		*create_stack(char **argv);
t_list		*get_node_by_sorted_index(t_list *head, int number);
t_list		*get_node_by_index(t_list *head, int number);
t_list		*get_node_by_rev_index(t_list *head, int number);
t_list		*get_node_by_content(t_list *head, void *number);
t_list		*find_lowest_val(t_list *head);
t_list		*create_first_quarter(t_list **head, int quart, int initial_size);
t_list		*create_first_quarter_rev(t_list **head,
				int quart, int initial_size);
t_list		*get_closest_to_index(t_list **quarter, t_list **head);
t_list		*get_lowest_number(t_list *head);
t_list		*get_max_number(t_list *head);
int			has_non_numeric_vals(char *argv);
int			has_duplicate_numbers(t_list *head);
int			is_sorted(t_list *head);
int			is_sorted_reverse(t_list *head);
int			stack_is_invalid(t_list *head);
int			get_divisor(int size);

#endif
