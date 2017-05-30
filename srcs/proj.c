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

void	ft_apply_proj_isoh(t_env *env, int x, int y)
{
	int		xo;
	int		yo;

	xo = x - env->x_max / 2;
	yo = y - env->y_max / 2;
	env->x1 = env->zoomx * (env->cx * xo - env->cy * yo);
	env->y1 = env->zoomy * (env->cx * xo + env->cy * yo) - 0.1 * env->cz * env->zoomz * env->map[y][x];
	env->x2 = env->zoomx * (env->cx * (xo + 1) - env->cy * yo);
	env->y2 = env->zoomy * (env->cx * (xo + 1) + env->cy * yo) - 0.1 * env->cz * env->zoomz * env->map[y][x + 1];
	env->x1 += SIZEX / 2;
	env->x2 += SIZEX / 2;
	env->y1 += SIZEY / 2;
	env->y2 += SIZEY / 2;
}

void	ft_apply_proj_isov(t_env *env, int x, int y)
{
	int		xo;
	int		yo;

	xo = x - env->x_max / 2;
	yo = y - env->y_max / 2;
	env->x1 = env->zoomx * (env->cx * xo - env->cy * yo);
	env->y1 = env->zoomy * (env->cx * xo + env->cy * yo) - 0.1 * env->cz *  env->zoomz * env->map[y][x];
	env->x2 = env->zoomx *(env->cx * xo - env->cy * (yo + 1));
	env->y2 = env->zoomy *(env->cx * xo + env->cy * (yo + 1)) - 0.1 * env->cz * env->zoomz * env->map[y + 1][x];
	env->x1 += SIZEX / 2;
	env->x2 += SIZEX / 2;
	env->y1 += SIZEY / 2;
	env->y2 += SIZEY / 2;
}
