/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:35:21 by awyart            #+#    #+#             */
/*   Updated: 2017/05/29 14:35:22 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "event.h"

int 	my_key_func(int keycode, t_env *env)
{
	int i;

	i = -1;
	while (++i < NBEVE)
	{
		if (keycode == g_ev[i].key)
		{
			g_ev[i].f(env);
			break ;
		}
	}
	//printf("%i\n",keycode);
	return (0);
}



int		main(int ac, char **av)
{
	t_env	*env;

	if (ac == 1)
		return (0);
	env = (t_env *)malloc(sizeof(t_env));
	if (ft_init_mlx(env) == 1)
		return (0);
	ft_getsize(av[1], env);
	ft_fill(av[1], env);
	ft_draw(env);
	mlx_key_hook(env->win, my_key_func, env);
	mlx_loop(env->mlx);
	return (0);
}
