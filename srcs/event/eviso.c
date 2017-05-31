/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eviso.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:37:18 by awyart            #+#    #+#             */
/*   Updated: 2017/05/30 16:37:48 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_evi(t_env *env)
{
	env->zoomx = SIZEX /(env->x_max + env->y_max);
	env->zoomy = SIZEY /(env->x_max + env->y_max);
	env->cx = 1;
	env->cy = 1;
	env->cz = 1;
	ft_draw(env);
}
