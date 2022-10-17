/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:08:54 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/17 04:08:16 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

long	ft_atoi(const char *str)
{
	long	x;
	int		i;
	long	sign;

	x = 0;
	i = 0;
	sign = 1;
	while (str[i] == 9 || str[i] == 32 || str[i] == 10 || str[i] == 11
		|| str[i] == 12 || str[i] == 13)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		x = x * 10 + str[i++] - '0';
	return (x * sign);
}
