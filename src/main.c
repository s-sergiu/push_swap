/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:32:30 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/13 20:45:02 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_lstprint(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	i = 0;
	
	while (tmp)
	{
		tmp = tmp->next;
		printf("content at %d is %d\n", i, *((int *)(tmp->content)));
		i++;
	}
}

int	main (int argc, char *argv[])
{
	int	i;

	t_list *list;
	list = register_input(argc, argv);

	i = ft_lstsize(list);
	ft_lstprint(list);

	printf("result is %d\n", i);
	
	return(0);
}
