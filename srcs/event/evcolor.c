/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evcolor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:22:33 by awyart            #+#    #+#             */
/*   Updated: 2017/05/30 16:22:35 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	ft_ev15(t_env *env)
{
	if (0 <= env->r && env->r < 80)
		env->r = 80;
	else if (80 <= env->r && env->r < 160)
		env->r = 160;
	else if (160 <= env->r && env->r < 210)
		env->r = 210;
	else if (env->r == 255)
		env->r = 0;
	else
		env->r = 255;
	ft_draw(env);
}

void 	ft_ev11(t_env *env)
{
	if (0 <= env->b && env->b < 80)
		env->b = 80;
	else if (80 <= env->b && env->b < 160)
		env->b = 160;
	else if (160 <= env->b && env->b < 210)
		env->b = 210;
	else if (env->b == 255)
		env->b = 0;
	else
		env->b = 255;
	ft_draw(env);
}

void 	ft_ev5(t_env *env)
{
	if (0 <= env->g && env->g < 80)
		env->g = 80;
	else if (80 <= env->g && env->g < 160)
		env->g = 160;
	else if (160 <= env->g && env->g < 210)
		env->g = 210;
	else if (env->g == 255)
		env->g = 0;
	else
		env->g = 255;
	ft_draw(env);
}

void 	ft_evo(t_env *env)
{
	if (env->r == 255 && env->g == 255 && env->b == 255)
	{
		env->r = 0;
		env->g = 0;
		env->b = 0;
	}
	else
	{
		env->r = 255;
		env->g = 255;
		env->b = 255;
	}
	ft_draw(env);
}

