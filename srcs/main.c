/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:56:18 by awyart            #+#    #+#             */
/*   Updated: 2017/06/02 12:24:03 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_define1_ev(t_ev ev[NBEVE])
{
	ev[0].key = 69;
	ev[1].key = 78;
	ev[2].key = 123;
	ev[3].key = 124;
	ev[4].key = 125;
	ev[5].key = 126;
	ev[6].key = 43;
	ev[7].key = 47;
	ev[8].key = 6;
	ev[9].key = 7;
	ev[10].key = 15;
	ev[11].key = 5;
	ev[12].key = 11;
	ev[13].key = 53;
	ev[14].key = 34;
	ev[15].key = 31;
	ev[16].key = 83;
	ev[17].key = 84;
	ev[18].key = 82;
	ev[19].key = 2;
	ev[20].key = 0;
	ev[21].key = 1;
	ev[22].key = 13;
	ev[23].key = 87;
	ev[24].key = 88;
}

static void	ft_define2_ev(t_ev ev[NBEVE])
{
	ev[0].f = &ft_ev69;
	ev[1].f = &ft_ev78;
	ev[2].f = &ft_ev123;
	ev[3].f = &ft_ev124;
	ev[4].f = &ft_ev125;
	ev[5].f = &ft_ev126;
	ev[6].f = &ft_ev43;
	ev[7].f = &ft_ev47;
	ev[8].f = &ft_ev6;
	ev[9].f = &ft_evx;
	ev[10].f = &ft_ev15;
	ev[11].f = &ft_ev5;
	ev[12].f = &ft_ev11;
	ev[13].f = &ft_exit;
	ev[14].f = &ft_evi;
	ev[15].f = &ft_evo;
	ev[16].f = &ft_colorset1;
	ev[17].f = &ft_colorset2;
	ev[18].f = &ft_evu;
	ev[19].f = &ft_evmv;
	ev[20].f = &ft_evmv1;
	ev[21].f = &ft_evmv2;
	ev[22].f = &ft_evmv3;
	ev[23].f = &ft_ev87;
	ev[24].f = &ft_ev88;
}

int			my_key_func(int keycode, t_env *env)
{
	int		i;
	t_ev	g_ev[NBEVE];

	i = -1;
	ft_define1_ev(g_ev);
	ft_define2_ev(g_ev);
	while (++i < NBEVE)
	{
		if (keycode == g_ev[i].key)
		{
			g_ev[i].f(env);
			break ;
		}
	}
	return (0);
}

int			main(int ac, char **av)
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
	mlx_expose_hook(env->win, &ft_draw, env);
	mlx_loop(env->mlx);
	return (0);
}
