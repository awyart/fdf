/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:38:24 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 15:46:06 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char			*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	if (!(dup = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
