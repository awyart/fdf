/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eviso.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:37:18 by awyart            #+#    #+#             */
/*   Updated: 2017/06/01 18:39:58 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_evi(t_env *env)
{
	env->zoomx = SIZEX / (env->x_max + env->y_max);
	env->zoomy = SIZEY / (env->x_max + env->y_max);
	env->zoomz = 1 / env->zmax;
	env->cx = 0;
	env->cy = 0;
	env->cz = 0;
	env->b = 255;
	env->g = 255;
	env->r = 255;
	env->mvx = 0;
	env->mvy = 0;
	ft_draw(env);
}

void	ft_evu(t_env *env)
{
	env->zoomz = 0;
	ft_draw(env);
}
