/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:22:09 by awyart            #+#    #+#             */
/*   Updated: 2017/04/11 11:22:12 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		result;
	int		test;

	i = 0;
	result = 0;
	test = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\n' || str[i] == '\b'
			|| str[i] == '\f' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		test = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = result * 10;
		result = result + (str[i] - 48);
		i = i + 1;
	}
	if (test == 1)
		result = -result;
	return (result);
}
