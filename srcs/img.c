/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:43:49 by awyart            #+#    #+#             */
/*   Updated: 2017/05/29 15:43:51 by awyart           ###   ########.fr       */
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

void	ft_draw(t_env *env)
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
