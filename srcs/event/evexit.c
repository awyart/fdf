/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:30:07 by awyart            #+#    #+#             */
/*   Updated: 2017/05/30 16:30:48 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(t_env *env)
{
	env->g = 5;
	exit(0);
}
