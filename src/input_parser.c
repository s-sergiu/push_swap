/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:33:34 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/14 21:49:56 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	is_valid_input(char c)
{
	return (0);
}

int	check_input(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i] != 0)
		if (!(ft_isdigit(argv[i]) || argv[i] == 32))
			return (0);
	return (1);
}

t_list	*create_stack(char **argv)
{
	int		i;
	int		j;
	t_list	*head;
	t_list	*new;
	char	**split;

	head = NULL;
	i = 0;
	while (argv[++i] != 0)
	{
		if (!check_input(argv[i]))
			return (NULL);
		else
		{
			split = ft_split(argv[i], ' ');
			j = 0;
			while (split[j] != 0)
			{
				new = ft_lstnew(split[j]);
				ft_lstadd_back(&head, new);
				j++;
			}
		}
	}
	return (head);
}
