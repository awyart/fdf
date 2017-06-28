/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:20:26 by awyart            #+#    #+#             */
/*   Updated: 2017/06/01 18:51:15 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_ev6(t_env *env)
{
	env->zoomz += 0.05;
	ft_draw(env);
}

void	ft_evx(t_env *env)
{
	env->zoomz -= 0.05;
	ft_draw(env);
}

void	ft_ev87(t_env *env)
{
	env->zoomz += 1;
	ft_draw(env);
}

void	ft_ev88(t_env *env)
{
	env->zoomz -= 1;
	ft_draw(env);
}
