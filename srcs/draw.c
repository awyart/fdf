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
		env->pix[(x * 4) + (y * SIZEX * 4)] = env->b;
		env->pix[(x * 4) + (y * SIZEX * 4) + 1] = env->g;
		env->pix[(x * 4) + (y * SIZEX * 4) + 2] = env->r;
	}
}

void	ft_draw_lines(t_env *env)
{
	int dx;
	int dy;
	int s[2];
	int err;
	int e2;

	dx= abs(env->x2 - env->x1);
	dy = abs(env->y2 - env->y1);
	err = 1 / 2 * ((dx > dy) ? (dx) : (-(dy)));
	s[0] = ((env->x1 < env->x2) ? (1) : (-1));
	s[1] = ((env->y1 < env->y2) ? (1) : (-1));
	while (1)
	{
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

