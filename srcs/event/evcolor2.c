/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evcolor2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 20:45:59 by awyart            #+#    #+#             */
/*   Updated: 2017/06/01 19:00:02 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_px(t_env *env, int x, int y)
{
	if ((x > 0 && y > 0) && (x <= SIZEX && y <= SIZEY))
	{
		env->pix[(x * 4) + (y * SIZEX * 4)] = env->b;
		env->pix[(x * 4) + (y * SIZEX * 4) + 1] = env->g;
		env->pix[(x * 4) + (y * SIZEX * 4) + 2] = env->r;
	}
}

static void	ft_get_color1(t_env *env, int z)
{
	int b[2];
	int r[2];
	int g[2];
	int zmax;

	z = abs(z);
	b[0] = 50;
	b[1] = 250;
	r[0] = 50;
	r[1] = 250;
	g[0] = 50;
	g[1] = 250;
	zmax = env->zmax;
	env->r = r[0] + (r[1] - r[0]) * z / zmax;
	env->g = g[0] + (g[1] - g[0]) * z / zmax;
	env->b = b[0] + (b[1] - b[0]) * z / zmax;
}

static int	ft_douille(t_env *env, int *dx, int *dy, int s[2])
{
	*dx = abs(env->x2 - env->x1);
	*dy = abs(env->y2 - env->y1);
	s[0] = ((env->x1 < env->x2) ? (1) : (-1));
	s[1] = ((env->y1 < env->y2) ? (1) : (-1));
	return (1 / 2 * ((*dx > *dy) ? (*dx) : (-(*dy))));
}

static void	ft_draw_lines_c(t_env *env, int z1)
{
	int dx;
	int dy;
	int s[2];
	int err;
	int e2;

	err = ft_douille(env, &dx, &dy, s);
	while (1)
	{
		ft_get_color1(env, z1);
		ft_put_px(env, env->x1, env->y1);
		if (env->x1 == env->x2 && env->y1 == env->y2)
			break ;
		e2 = err;
		if (e2 > -(dx))
		{
			err -= dy;
			env->x1 += s[0];
		}
		if (e2 < dy)
		{
			err += dx;
			env->y1 += s[1];
		}
	}
}

void		ft_colorset1(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = -1;
	ft_create_img(env);
	while (++y < env->y_max)
	{
		while (x < env->x_max)
		{
			if (x + 1 < env->x_max && ZZ != NOZ && ZZZ != NOZ)
			{
				ft_apply_proj_isoh(env, x, y);
				ft_draw_lines_c(env, ZZ);
			}
			if (y + 1 < env->y_max && ZZ != NOZ && ZZZZ != NOZ)
			{
				ft_apply_proj_isov(env, x, y);
				ft_draw_lines_c(env, ZZ);
			}
			x++;
		}
		x = 0;
	}
	ft_display_img(env);
}
