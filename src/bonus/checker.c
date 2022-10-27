/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:02:46 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/27 18:53:36 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

void	instruction_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	check_instructions_loop(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(line, "rra", 3) && line[4] == 0)
		rra(stack_a, 1);
	else if (!ft_strncmp(line, "rrb", 3) && line[4] == 0)
		rrb(stack_b, 1);
	else if (!ft_strncmp(line, "rrr", 3) && line[4] == 0)
		rrr(stack_a, stack_b, 1);
	else if (!ft_strncmp(line, "sa", 2) && line[3] == 0)
		sa(stack_a, 1);
	else if (!ft_strncmp(line, "sb", 2) && line[3] == 0)
		sb(stack_b, 1);
	else if (!ft_strncmp(line, "ss", 2) && line[3] == 0)
		ss(stack_a, stack_b, 1);
	else if (!ft_strncmp(line, "pa", 2) && line[3] == 0)
		pa(stack_a, stack_b, 1);
	else if (!ft_strncmp(line, "pb", 2) && line[3] == 0)
		pb(stack_a, stack_b, 1);
	else if (!ft_strncmp(line, "ra", 2) && line[3] == 0)
		ra(stack_a, 1);
	else if (!ft_strncmp(line, "rb", 2) && line[3] == 0)
		rb(stack_b, 1);
	else if (!ft_strncmp(line, "rr", 2) && line[3] == 0)
		rr(stack_a, stack_b, 1);
	else
		instruction_error();
}

void	check_instructions(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		check_instructions_loop(line, stack_a, stack_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = create_stack(argv);
	init_indexes(&stack_a);
	if (stack_is_invalid(stack_a))
	{
		ft_lstclear(&stack_a, free);
		return (0);
	}
	check_instructions(&stack_a, &stack_b);
	if ((stack_a && is_sorted(stack_a)) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
