/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evrot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:17:02 by awyart            #+#    #+#             */
/*   Updated: 2017/05/30 16:17:03 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdlib.h"

void 	ft_ev123(t_env *env)
{
	env->cx += 10;
	ft_draw(env);
}

void 	ft_ev124(t_env *env)
{
	env->cx -= 10;
	ft_draw(env);
}

void 	ft_ev125(t_env *env)
{
	env->cy += 10;
	ft_draw(env);
}

void 	ft_ev126(t_env *env)
{
	env->cy -= 10;
	ft_draw(env);
}

