/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evcolor2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 20:45:59 by awyart            #+#    #+#             */
/*   Updated: 2017/05/30 20:46:00 by awyart           ###   ########.fr       */
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

static void	ft_define_earth(int b[2], int r[2], int g[2])
{
	b[0] = 107;
	b[1] = 12;
	r[0] = 255;
	r[1] = 157;
	g[0] = 255;
	g[1] = 52;
}

static void	ft_define_sea(int b[2], int r[2], int g[2])
{
	b[0] = 255;
	b[1] = 180;
	r[0] = 0;
	r[1] = 1;
	g[0] = 0;
	g[1] = 49;
}

static void	ft_define_forrest(int b[2], int r[2], int g[2])
{
	b[0] = 3;
	b[1] = 15;
	r[0] = 86;
	r[1] = 34;
	g[0] = 130;
	g[1] = 120;
}

static void	ft_define_moutain(int b[2], int r[2], int g[2])
{
	b[0] = 107;
	b[1] = 230;
	r[0] = 80;
	r[1] = 230;
	g[0] = 94;
	g[1] = 230;
}


static void ft_get_color(t_env *env, int z)
{
	int b[2];
	int r[2];
	int g[2];
	int zmax;

	if (z < 0)
		z = 0;
	zmax = env->zmax;
	if (z < 0)
		ft_define_sea(b, r, g);
	if (0 < z/zmax && z/zmax <= 0.05)
		ft_define_earth(b, r, g);
	if (0.05 < z/zmax && z/zmax <= 0.2)
		ft_define_forrest(b, r, g);
	if (0.2 < z/zmax && z/zmax <= 1)
		ft_define_moutain(b, r, g);
	env->r =  r[0] + (r[1] - r[0]) * z/zmax;
	env->g =  g[0] + (g[1] - g[0]) * z/zmax;
	env->b =  r[0] + (b[1] - b[0]) * z/zmax;
}

static void	ft_draw_lines_c(t_env *env, int z1, int z2)
{
	int dx;
	int dy;
	int s[2];
	int err[2];
	int e2;

	dx = abs(env->x2 - env->x1);
	dy = abs(env->y2 - env->y1);
	err[0] = 1 / 2 * ((dx > dy) ? (dx) : (-(dy)));
	err[1] = ((dx + dy == 0) ? 0 : (z2 - z1) / (dx + dy));
	s[0] = ((env->x1 < env->x2) ? (1) : (-1));
	s[1] = ((env->y1 < env->y2) ? (1) : (-1));
	while (1)
	{
		ft_get_color(env, z1 + err[1]);
		ft_put_px(env, env->x1, env->y1);
		if (env->x1 == env->x2 && env->y1 == env->y2)
			break ;
		e2 = err[0];
		if (e2 > -(dx))
		{
			err[0] -= dy;
			env->x1 += s[0];
		}
		if (e2 < dy)
		{
			err[0] += dx;
			env->y1 += s[1];
		}
	}
}

void	ft_colorset2(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_create_img(env);
	while (y < env->y_max)
	{
		while (x < env->x_max)
		{
			if (x + 1 < env->x_max && env->map[y][x] != NOZ
				&& env->map[y][x + 1] != NOZ)
			{
				ft_apply_proj_isoh(env, x, y);
				ft_draw_lines_c(env, env->map[y][x], env->map[y][x + 1]);
			}
			if (y + 1 < env->y_max && env->map[y][x] != NOZ
				&& env->map[y + 1][x] != NOZ)
			{
				ft_apply_proj_isov(env, x, y);
				ft_draw_lines_c(env, env->map[y][x], env->map[y + 1][x]);
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_display_img(env);
}
