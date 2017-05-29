/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:39:22 by awyart            #+#    #+#             */
/*   Updated: 2017/05/23 15:46:35 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst_tmp;
	unsigned char *src_tmp;

	dst_tmp = dst;
	src_tmp = (unsigned char*)src;
	if (dst < src)
	{
		while (len--)
			*dst_tmp++ = *src_tmp++;
	}
	else
	{
		while (len--)
			dst_tmp[len] = src_tmp[len];
	}
	return (dst);
}
