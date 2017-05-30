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

static void	ft_display_img(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}

static void	ft_create_img(t_env *env)
{
	int		bpp;
	int		sizeline;
	int		endian;

	env->img = mlx_new_image(env->mlx, SIZEX, SIZEY);
	env->pix = mlx_get_data_addr(env->img, &bpp, &sizeline, &endian);
}

static int ft_getmax(t_env *env)
{
	int i;
	int j;
	int c;

	i = -1;
	j = -1;
	c = 1;
	while (++i < env->y_max)
	{
		while(++j < env->x_max)
		{
			if (abs(env->map[i][j] > c))
				c = abs(env->map[i][j]);
		}
	}
	return (c);
}


static void ft_get_color(t_env *env, int z)
{
	int zmax = 1;
	int b[2];
	int r[2];
	int g[2];

	b[0] = 255;
	b[1] = 255;
	r[0] = 200;
	r[1] = 255;
	g[0] = 200;
	g[1] = 255;
	zmax = ft_getmax(env) / 2;
	env->r =  r[0] * (1 - z/zmax) + r[1] * z/zmax;
	env->g =  g[0] * (1 - z/zmax) + g[1] * z/zmax;
	env->b =  b[0] * (1 - z/zmax) + b[1] * z/zmax;
}

void	ft_colorset1(t_env *env)
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
			ft_get_color(env, env->map[y][x]);
			if (x + 1 < env->x_max && env->map[y][x] != NOZ
				&& env->map[y][x + 1] != NOZ)
			{
				ft_apply_proj_isoh(env, x, y);
				ft_draw_lines(env);
			}
			if (y + 1 < env->y_max && env->map[y][x] != NOZ
				&& env->map[y + 1][x] != NOZ)
			{
				ft_apply_proj_isov(env, x, y);
				ft_draw_lines(env);
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_display_img(env);
}
