/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:56:32 by awyart            #+#    #+#             */
/*   Updated: 2017/06/01 18:00:47 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_getmax(t_env *env)
{
	int i;
	int j;
	int c;

	i = -1;
	j = -1;
	c = 1;
	while (++i < env->y_max)
	{
		while (++j < env->x_max)
		{
			if (abs(env->map[i][j] > c) && env->map[i][j] != NOZ)
				c = abs(env->map[i][j]);
		}
		j = 0;
	}
	return (c);
}

static void	ft_fillmap(t_env *env, char **split, int *i, int j)
{
	int		k;

	k = 0;
	while (split[k] && *i != env->x_max)
	{
		env->map[j][*i] = ft_atoi(split[k]);
		(*i)++;
		k++;
	}
	while (*i != env->x_max)
	{
		env->map[j][*i] = NOZ;
		(*i)++;
	}
}

void		ft_fill(char *av, t_env *env)
{
	char	*line;
	char	**split;
	int		j;
	int		i;
	int		fd;

	i = 0;
	j = 0;
	if (!av)
		return ;
	fd = open(av, O_RDONLY);
	env->map = (int**)malloc(sizeof(int*) * env->y_max);
	while (get_next_line(fd, &line) == 1)
	{
		env->map[j] = (int*)malloc(sizeof(int) * env->x_max);
		split = ft_strsplit(line, ' ');
		if (split)
			ft_fillmap(env, split, &i, j);
		i = 0;
		if (split)
			free(split);
		j++;
	}
	close(fd);
	env->zmax = ft_getmax(env);
}
