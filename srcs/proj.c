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

void	ft_apply_proj_iso(t_env *env, int x, int y)
{
	int		xo;
	int		yo;

	xo = x - env->x_max / 2;
	yo = y - env->y_max / 2;
	env->x1 = env->zoom * 0.40 * (xo - yo);
	env->y1 = env->zoom * 0.20 *(xo + yo) - env->map[y][x];
	env->x2 = env->zoom * 0.40 * ((xo + 1) - yo);
	env->y2 = env->zoom * 0.20 *((xo + 1) + yo) - env->map[y][x + 1];
	env->x1 += SIZEX / 2;
	env->x2 += SIZEX / 2;
	env->y1 += SIZEY / 2;
	env->y2 += SIZEY / 2;
}

void	ft_apply_proj_iso_end(t_env *env, int x, int y)
{
	int		xo;
	int		yo;

	xo = x - env->x_max / 2;
	yo = y - env->y_max / 2;
	env->x1 = env->zoom * 0.40 * (xo - yo);
	env->y1 = env->zoom * 0.20 *(xo + yo) - env->map[y][x];
	env->x2 = env->zoom * 0.40 * (xo - (yo + 1));
	env->y2 = env->zoom * 0.20 *(xo + (yo + 1)) - env->map[y + 1][x];
	env->x1 += SIZEX / 2;
	env->x2 += SIZEX / 2;
	env->y1 += SIZEY / 2;
	env->y2 += SIZEY / 2;
}
