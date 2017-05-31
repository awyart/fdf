/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:17:33 by awyart            #+#    #+#             */
/*   Updated: 2017/05/29 16:17:34 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_new_x(t_env *env, int x, int y, int z)
{
	int res;
	double	b;
	double	c;

	b = env->cy * 2 * M_PI / 360 ;
	c = env->cz * 2 * M_PI / 360 ;
	res = cos(b) * cos(c) * x - sin(c) * cos(b) * y + sin(b) * z;
	res -= env->x_max / 2;
	return (res);
}

int		ft_get_new_y(t_env *env, int x, int y, int z)
{
	int res;
	double	a;
	double	b;
	double	c;

	a = env->cx * 2 * M_PI / 360 ;
	b = env->cy * 2 * M_PI / 360 ;
	c = env->cz * 2 * M_PI / 360 ;
	res = (sin(a) * sin(b) * cos(c) + cos(a) * sin(c)) * x
			+ (cos(a) * cos(c) - sin(a) * sin(b) * sin(z)) * y
				+(cos(b) * sin(a)) * z;
	res -= env->y_max / 2;
	return (res);
	
}

int		ft_get_new_z(t_env *env, int x, int y, int z)
{
	int res;
	double	a;
	double	b;
	double	c;

	a = env->cx * 2 * M_PI / 360 ;
	b = env->cy * 2 * M_PI / 360 ;
	c = env->cz * 2 * M_PI / 360 ;
	res = -(cos(a) * sin(b) * cos(c) + cos(a) * sin(c)) * x
			+ (cos(a) * sin(b) *sin(c) - cos(c) * sin(a)) * y
				+(cos(a) * cos(b)) * z;
	return (res);
	
}

void	ft_apply_proj_isoh(t_env *env, int x, int y)
{
	int		zo[2];
	int		xo[2];
	int		yo[2];

	xo[0] = ft_get_new_x(env, x, y, env->map[y][x]);
	yo[0] = ft_get_new_y(env, x, y, env->map[y][x]);
	zo[0] = ft_get_new_z(env, x, y, env->map[y][x]);
	xo[1] = ft_get_new_x(env, x + 1, y, env->map[y][x + 1]);
	yo[1] = ft_get_new_y(env, x + 1, y, env->map[y][x + 1]);
	zo[1] = ft_get_new_z(env, x + 1, y, env->map[y][x + 1]);
	env->x1 = env->zoomx * 0.7 * (xo[0] - yo[0]);
	env->y1 = env->zoomy * 0.4 * (xo[0] + yo[0]) - 0.2 * 0.8 * env->zoomz * zo[0];
	env->x2 = env->zoomx * 0.7 * (xo[1] - yo[1]);
	env->y2 = env->zoomy * 0.4 * (xo[1] + yo[1]) - 0.2 * 0.8 * env->zoomz * zo[1];
	env->x1 += SIZEX / 2;
	env->x2 += SIZEX / 2;
	env->y1 += SIZEY / 2;
	env->y2 += SIZEY / 2;
}

void	ft_apply_proj_isov(t_env *env, int x, int y)
{
	int		zo[2];
	int		xo[2];
	int		yo[2];

	xo[0] = ft_get_new_x(env, x, y, env->map[y][x]);
	yo[0] = ft_get_new_y(env, x, y, env->map[y][x]);
	zo[0] = ft_get_new_z(env, x, y, env->map[y][x]);
	xo[1] = ft_get_new_x(env, x , y + 1, env->map[y + 1][x]);
	yo[1] = ft_get_new_y(env, x , y + 1, env->map[y + 1][x]);
	zo[1] = ft_get_new_z(env, x , y + 1, env->map[y + 1][x]);
	env->x1 = env->zoomx * 0.7 * (xo[0] - yo[0]);
	env->y1 = env->zoomy * 0.4 * (xo[0] + yo[0]) - 0.2 * 0.8 * env->zoomz * zo[0];
	env->x2 = env->zoomx * 0.7 * (xo[1] - yo[1]);
	env->y2 = env->zoomy * 0.4 * (xo[1] + yo[1]) - 0.2 * 0.8 * env->zoomz * zo[1];
	env->x1 += SIZEX / 2;
	env->x2 += SIZEX / 2;
	env->y1 += SIZEY / 2;
	env->y2 += SIZEY / 2;
}
