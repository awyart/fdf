/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evmv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:23:42 by awyart            #+#    #+#             */
/*   Updated: 2017/06/01 14:23:44 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_evmv(t_env *env)
{
	env->mvx += 25;
	ft_draw(env);
}

void	ft_evmv1(t_env *env)
{
	env->mvx -= 25;
	ft_draw(env);
}

void	ft_evmv2(t_env *env)
{
	env->mvy += 25;
	ft_draw(env);
}

void	ft_evmv3(t_env *env)
{
	env->mvy -= 25;
	ft_draw(env);
}
