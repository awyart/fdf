/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:56:00 by awyart            #+#    #+#             */
/*   Updated: 2017/06/02 11:49:56 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_display_img(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
	return (1);
}

void	ft_create_img(t_env *env)
{
	int		bpp;
	int		sizeline;
	int		endian;

	env->img = mlx_new_image(env->mlx, SIZEX, SIZEY);
	env->pix = mlx_get_data_addr(env->img, &bpp, &sizeline, &endian);
}

int		ft_draw(t_env *env)
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
				ft_draw_lines(env);
			}
			if (y + 1 < env->y_max && ZZ != NOZ && ZZZZ != NOZ)
			{
				ft_apply_proj_isov(env, x, y);
				ft_draw_lines(env);
			}
			x++;
		}
		x = 0;
	}
	return (ft_display_img(env));
}
