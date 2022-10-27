/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:39:31 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 16:33:23 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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
void		free_split(char **split);
void		clear_and_free_split(t_list **head, char **split);
void		remove_from_list(void *number, t_list **head);
void		init_indexes(t_list **head);
int			has_non_numeric_vals(char *argv);
char		*get_next_line(int fd);
t_list		*create_stack(char **argv);
int			has_duplicate_numbers(t_list *head);
int			is_sorted(t_list *head);
int			stack_is_invalid(t_list *head);

#endif
