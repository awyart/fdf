/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:34:55 by awyart            #+#    #+#             */
/*   Updated: 2017/05/29 14:34:58 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_px(t_env *env, int x, int y)
{
	if ((x > 0 && y > 0) && (x <= SIZEX && y <= SIZEY))
	{
		env->pix[(x * 4) + (y * SIZEX * 4)] = env->r;
		env->pix[(x * 4) + (y * SIZEX * 4) + 1] = env->g;
		env->pix[(x * 4) + (y * SIZEX * 4) + 2] = env->b;
	}
}

void	ft_draw_lines(t_env *env)
{
	double dx;
	double dy;
	double x;
	double y;
	double temp;

	x = env->x1;
	y = env->y1;
	dx = env->x2 - env->x1;
	dy = env->y2 - env->y1;
	temp = sqrt((dx * dx) + (dy * dy));
	dx /= temp;
	dy /= temp;
	while (temp >= 0)
	{
		ft_put_px(env, x, y);
		x += dx;
		y += dy;
		temp--;
	}
}

