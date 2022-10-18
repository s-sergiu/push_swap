/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:46:39 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/18 15:58:58 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i] != 0)
		free(str[i]);
	free(str);
}

int	create_stack_loop(t_create_stack *new)
{
	while (new->split[++new->j] != 0)
	{
		if (!xcheck_input(new->split[new->j]))
			return (0);
		new->content = (long *)malloc(sizeof(long) * 1);
		if (!new->content)
			return (0);
		*new->content = ft_atoi(new->split[new->j]);
		if (*new->content < -2147483648 || *new->content > 2147483647)
			return (0);
		new->new = ft_lstnew(new->content);
		ft_lstadd_back(&new->head, new->new);
	}
	free_split(new->split);
	return (1);
}

t_list	*create_stack(char **argv)
{
	t_create_stack	*new;

	new->head = NULL;
	new->i = 0;
	while (argv[++new->i] != 0)
	{
		new->split = ft_split(argv[new->i], ' ');
		new->j = -1;
		if (!create_stack_loop(new))
			return (NULL);
	}
	return (new->head);
}
