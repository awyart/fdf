/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eve.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:05:14 by awyart            #+#    #+#             */
/*   Updated: 2017/05/30 16:05:15 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	ft_ev69(t_env *env)
{
	if (env->zoomx <= 1)
		env->zoomx += 1;
	else if (env->zoomx < 5)
		env->zoomx += 1;
	else 
		env->zoomx += env->zoomx / 5;
	if (env->zoomy <= 1)
		env->zoomy += 1;
	else if (env->zoomy < 5)
		env->zoomy += 1;
	else 
		env->zoomy += env->zoomy / 5;
	if (env->zoomz <= 1)
		env->zoomz += 1;
	else if (env->zoomz < 5)
		env->zoomz += 1;
	else 
		env->zoomz += env->zoomz / 5;
	ft_draw(env);
}

void 	ft_ev78(t_env *env)
{
	if (env->zoomx <= 1)
		env->zoomx = 1;
	else if (env->zoomx < 5)
		env->zoomx -= 1;
	else 
		env->zoomx -= env->zoomx / 5;
	if (env->zoomy <= 1)
		env->zoomy = 1;
	else if (env->zoomy < 5)
		env->zoomy -= 1;
	else 
		env->zoomy -= env->zoomy / 5;
	if (env->zoomz <= 1)
		env->zoomz = 1;
	else if (env->zoomz < 5)
		env->zoomz -= 1;
	else 
		env->zoomz -= env->zoomz / 5;
	ft_draw(env);
}