/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evcolor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:22:33 by awyart            #+#    #+#             */
/*   Updated: 2017/06/02 12:17:19 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_color(t_env *env, int z)
{
	int		b[2];
	int		r[2];
	int		g[2];
	int		zmax;
	double	i;

	zmax = env->zmax;
	if (zmax == 0)
		zmax = 1;
	i = (double)z / (double)zmax;
	if (z < 0)
		z = 0;
	if (i <= 0.002)
		ft_define_sea(b, r, g);
	else if (i <= 0.01)
		ft_define_beach(b, r, g);
	else if (i <= 0.08)
		ft_define_earth(b, r, g);
	else if (i <= 0.35)
		ft_define_forrest(b, r, g);
	else if (i <= 1)
		ft_define_moutain(b, r, g);
	env->r = r[0] + (r[1] - r[0]) * z / zmax;
	env->g = g[0] + (g[1] - g[0]) * z / zmax;
	env->b = b[0] + (b[1] - b[0]) * z / zmax;
}

void	ft_ev15(t_env *env)
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

void	ft_ev11(t_env *env)
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

void	ft_ev5(t_env *env)
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

void	ft_evo(t_env *env)
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
