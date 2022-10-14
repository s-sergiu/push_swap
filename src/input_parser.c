/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:33:34 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/13 20:48:21 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

t_list	*register_input(int argc, char **argv)
{
	t_list	*head;
	t_list	*new;
	char	**split;
	int		*content;
	int		i;
	int		j;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);

	i = 0;
	//create list
	while (++i < argc)
	{
		//loop over every argument
		split = ft_split(argv[i], ' ');
		j = -1;
		while (split[++j] != 0)
		{
			content = malloc(1 * sizeof(int));
			*content = ft_atoi(split[j]);
			new = ft_lstnew(content);
			ft_lstadd_back(&head, new);
			printf("split at %d is: %s\n", i, split[j]);
		}
	}
	return (head);
}
