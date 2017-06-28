/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:56:25 by awyart            #+#    #+#             */
/*   Updated: 2017/06/01 18:49:30 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	ft_get_new_x(t_env *env, int x, int y, int z)
{
	double	res;
	double	b;
	double	c;

	b = env->cy * 2 * M_PI / 360;
	c = env->cz * 2 * M_PI / 360;
	x -= env->x_max / 2;
	y -= env->y_max / 2;
	res = cos(b) * cos(c) * (double)x
			- sin(c) * cos(b) * (double)y
				+ sin(b) * (double)z;
	return (res);
}

static double	ft_get_new_y(t_env *env, int x, int y, int z)
{
	double	res;
	double	a;
	double	b;
	double	c;

	a = env->cx * 2 * M_PI / 360;
	b = env->cy * 2 * M_PI / 360;
	c = env->cz * 2 * M_PI / 360;
	x -= env->x_max / 2;
	y -= env->y_max / 2;
	res = (sin(a) * sin(b) * cos(c) + cos(a) * sin(c)) * (double)x
			+ (cos(a) * cos(c) - sin(a) * sin(b) * sin(z)) * (double)y
				+ (cos(b) * sin(a)) * (double)z;
	return (res);
}

static double	ft_get_new_z(t_env *env, int x, int y, int z)
{
	double	res;
	double	a;
	double	b;
	double	c;

	a = env->cx * 2 * M_PI / 360;
	b = env->cy * 2 * M_PI / 360;
	c = env->cz * 2 * M_PI / 360;
	x -= env->x_max / 2;
	y -= env->y_max / 2;
	res = -(cos(a) * sin(b) * cos(c) + cos(a) * sin(c)) * (double)x
			+ (cos(a) * sin(b) * sin(c) - cos(c) * sin(a)) * (double)y
				+ (cos(a) * cos(b)) * (double)z;
	return (res);
}

void			ft_apply_proj_isoh(t_env *env, int x, int y)
{
	double	zo[2];
	double	xo[2];
	double	yo[2];

	xo[0] = ft_get_new_x(env, x, y, env->zoomz * env->map[y][x]);
	yo[0] = ft_get_new_y(env, x, y, env->zoomz * env->map[y][x]);
	zo[0] = ft_get_new_z(env, x, y, env->zoomz * env->map[y][x]);
	xo[1] = ft_get_new_x(env, x + 1, y, env->zoomz * env->map[y][x + 1]);
	yo[1] = ft_get_new_y(env, x + 1, y, env->zoomz * env->map[y][x + 1]);
	zo[1] = ft_get_new_z(env, x + 1, y, env->zoomz * env->map[y][x + 1]);
	env->x1 = env->zoomx * 0.7 * (xo[0] - yo[0]) + env->mvx;
	env->y1 = env->zoomy * 0.4 * (xo[0] + yo[0]) - 0.8 * zo[0] + env->mvy;
	env->x2 = env->zoomx * 0.7 * (xo[1] - yo[1]) + env->mvx;
	env->y2 = env->zoomy * 0.4 * (xo[1] + yo[1]) - 0.8 * zo[1] + env->mvy;
	env->x1 += SIZEX / 2;
	env->x2 += SIZEX / 2;
	env->y1 += SIZEY / 2;
	env->y2 += SIZEY / 2;
}

void			ft_apply_proj_isov(t_env *env, int x, int y)
{
	double	zo[2];
	double	xo[2];
	double	yo[2];

	xo[0] = ft_get_new_x(env, x, y, env->zoomz * env->map[y][x]);
	yo[0] = ft_get_new_y(env, x, y, env->zoomz * env->map[y][x]);
	zo[0] = ft_get_new_z(env, x, y, env->zoomz * env->map[y][x]);
	xo[1] = ft_get_new_x(env, x, y + 1, env->zoomz * env->map[y + 1][x]);
	yo[1] = ft_get_new_y(env, x, y + 1, env->zoomz * env->map[y + 1][x]);
	zo[1] = ft_get_new_z(env, x, y + 1, env->zoomz * env->map[y + 1][x]);
	env->x1 = env->zoomx * 0.7 * (xo[0] - yo[0]) + env->mvx;
	env->y1 = env->zoomy * 0.4 * (xo[0] + yo[0]) - 0.8 * zo[0] + env->mvy;
	env->x2 = env->zoomx * 0.7 * (xo[1] - yo[1]) + env->mvx;
	env->y2 = env->zoomy * 0.4 * (xo[1] + yo[1]) - 0.8 * zo[1] + env->mvy;
	env->x1 += SIZEX / 2;
	env->x2 += SIZEX / 2;
	env->y1 += SIZEY / 2;
	env->y2 += SIZEY / 2;
}
