/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evrot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:17:02 by awyart            #+#    #+#             */
/*   Updated: 2017/05/30 16:17:03 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdlib.h"

void 	ft_ev123(t_env *env)
{
	if (env->cx <= -1)
		env->test = 0;
	else if (env->cx >= 1)
		env->test = 1;
	if (env->cx < 0)
		env->zoomz = - abs(env->zoomz);
	else
		env->zoomz = abs(env->zoomz);
	if (env->test == 0)
		env->cx += .1;
	else
		env->cx -= .1;
	ft_draw(env);
}

void 	ft_ev124(t_env *env)
{
	if (env->cx <= -1)
		env->test = 1;
	else if (env->cx >= 1)
		env->test = 0;
	if (env->cx < 0)
		env->zoomz = - abs(env->zoomz);
	else
		env->zoomz = abs(env->zoomz);
	if (env->test == 0)
		env->cx -= .1;
	else
		env->cx += .1;
	ft_draw(env);
}

void 	ft_ev125(t_env *env)
{
	if (env->cy <= -1)
		env->test = 0;
	else if (env->cy >= 1)
		env->test = 1;
	if (env->cy < 0)
		env->zoomz = - abs(env->zoomz);
	else
		env->zoomz = abs(env->zoomz);
	if (env->test == 0)
		env->cy += .1;
	else
		env->cy -= .1;
	ft_draw(env);
}

void 	ft_ev126(t_env *env)
{
	if (env->cy <= -1)
		env->test = 1;
	else if (env->cy >= 1)
		env->test = 0;
	if (env->cy < 0)
		env->zoomz = - abs(env->zoomz);
	else
		env->zoomz = abs(env->zoomz);
	if (env->test == 0)
		env->cy -= .1;
	else
		env->cy += .1;
	ft_draw(env);
}

